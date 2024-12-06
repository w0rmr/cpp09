#include "BitcoinExchange.hpp"
#include <exception>
#include <limits>
btc::btc(){}
btc::~btc(){}
btc::btc(std::string file_path, std::string csv_path){
    data_(csv_path);
    // std::cout << "pass data" << std::endl;
    input_(file_path);
}

void btc::print(float rate, const std::string date) {
    std::cout << date << " => ";
    std::map<std::string, float>::iterator it = data.find(date);
    if (it != data.end())
        std::cout << it->second * rate;
    else
        std::cout << data.upper_bound(date)->second * rate;
    std::cout << std::endl;
}

void btc::parse_file(void){

}

bool btc::check_month(unsigned int month){
    return (month > 0 && month < 13);
}

bool btc::isleap(unsigned int year){
    // Return true if year  
    // is a multiple of 4 and 
    // not multiple of 100. 
    // OR year is multiple of 400. 
    return (((year % 4 == 0) &&  
         (year % 100 != 0)) || 
         (year % 400 == 0)); 

}
bool btc::check_day(unsigned int day ,unsigned int month , unsigned int year){
        if(day > 31 || day < 1)
            return false;
        else if(month == 2)
        {
            if(isleap(year))
                return (day <= 29);
            else
                return (day <= 28);
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11)
            return (day <= 30);
        return true;
}

bool btc::check_year(unsigned int year){
    return ( 2009 < year && year < 9999);
}

bool btc::check_date(std::string date){
    // std::cout << "the date is => "<< date << std::endl;
    unsigned int year , month , day;
    char dash1  , dash2 ;
    // int leap_year;
    std::istringstream stream(date);
    if (!(stream >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-') {
        err_str = "bad input =>";
        err_str += date;
        return false;
    }
    else if (!check_year(year) || !check_month(month) || !check_day(day,month,year)){
        
        err_str = "bad input =>";
        err_str += date;
        return false;
    }
    return true;
}
void btc::err(){
    std::cerr << "Error: " << err_str << std::endl;
}
void btc::check_and_print(void){
    std::string line;
    std::ifstream file(input_path);
    if(!file.is_open()){
        err_str = "could not open file.";
        err();
    }
    std::getline(file, line);
    while(std::getline(file,line)){
        char *cstr = new char[line.size() + 1];
        std::strcpy(cstr, line.c_str());
        char *key = strtok(cstr,"|");
        char *value = strtok(NULL,"|");
        if(!value || !key){
            err_str = "bad input ";
            if(!value && key)
                err_str += " no value";
            err();
        }
        else if(!check_data(key,3) ||  !check_data(value,2) || !check_date(key) || !check_data(key,3) ||  !check_data(value,2) || !check_date(key))
            err();
        else{
            float float_v = std::strtof(value,NULL);
            if(float_v >= INT_MAX){
                err_str = "too large a number.";
                err();
            }
            else 
                print(float_v,key);
        }
        delete[] cstr;
        }
    file.close();
}

void btc::input_(std::string input){
    input_path = input;
    check_and_print();
}


std::ostream &operator<<(std::ostream &o , btc &BTC){
    (void) BTC;
    o << "btc\n" ;
    return o;
}

bool btc::isdigit_(std::string nbr){
    for(unsigned long i = 0 ; i < nbr.size() ;i++)
        if(!isdigit(nbr[i]) && nbr[i] != ' ')
            return false;
    return true;

}

bool btc::isdigit_(std::string nbr,char ignor){
    for(unsigned long i = 0 ; i < nbr.size() ;i++)
    {
        if(nbr[i]== '-'){
            err_str = "not a positive number.";
            return false;
        }
        else if(!isdigit(nbr[i]) && nbr[i] != ignor && nbr[i] != ' ' ){
            err_str = "not a valid number.";
            return false;
            }
    }
    return true;

}

bool btc::check_data(std::string data,int order){
    if (order == 1 || order == 3){ 
        if( order == 1 && data.size() > 10)
            return false;
        else if( order == 3 && ((data[data.size() - 1] = ! ' ' ) || data.size() > 11 ) )
            return false;
        else if(data[4] != data[7] &&  data[7] != '-')
            return false ;
        char *cstr = new char[data.size() + 1];
        cstr = std::strcpy(cstr,data.c_str());
        char * value = strtok(cstr,"-");
        while (value)
        {
            if(!isdigit_(value))
                return false;
            value = strtok(NULL,"-");
        }
        delete[] cstr;
    }else if(order == 2)
    {
        if(!isdigit_(data,'.'))
            return false;
    }
    return true;

}

void btc::data_(std::string path){
    data_path = path;
    std::string line;
    std::ifstream file(data_path);
    if(!file.is_open()){
        err_str ="could not open file.";
        err();
        std::exit(1);
    };
    std::getline(file, line);
    while(std::getline(file,line)){
        char *cstr = new char[line.size() + 1];
        std::strcpy(cstr, line.c_str());
        char *key = strtok(cstr,",");
        char *value = strtok(NULL,",");
        if(!check_data(key,1) ||  !check_data(value,2)){
            err_str = "bad database.";
            err();
            exit(1);
        };
        if(key && value)
            data[key] = (float)std::strtof(value,NULL);
        else if( strtok(NULL,",") != NULL){
            delete[] cstr;
            err_str = "bad database.";
            err();
            exit(1);
        }else{
            delete[] cstr;
            err_str = "bad database.";
            err();
            exit(1);
        }
        delete[] cstr;
        }
    file.close();
}

