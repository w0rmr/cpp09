#include "BitcoinExchange.hpp"
#include <exception>
btc::btc(){}
btc::~btc(){}
btc::btc(std::string file_path, std::string csv_path){
    data_(csv_path);
    std::cout << "pass data" << std::endl;
    input_(file_path);
}

void btc::add_to_data(std::string line){
    (void) line ;

}

struct check_value
{
  check_value( std::string value ) : value_(value) {}
  bool operator()( const std::pair<std::string, float>& v ) const 
  { 
    return (v.first == value_); 
  }
private:
  std::string value_;
};



void btc::print(float rate , std::string date){
    std::cout << "rate is -> " << rate << std::endl;
    std::cout << date << " => " ;
    if(std::find_if(data.begin(),data.end(),check_value(date)) != data.end()){
        std::cout << "the value(1) is " << data.lower_bound(date)->second << std::endl;
        std::cout << data.lower_bound(date)->second * rate;
    }else{
        std::cout << "the value(2) is " <<  data[date] << std::endl;
        std::cout <<  data[date] * rate;
    }
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
        return false;
    }
    else if (!check_year(year))
        return false;
    else if (!check_month(month))
        return false;
    else if(!check_day(day,month,year))
        return false;
    return true;
}

void btc::check_and_print(void){
    std::string line;
    std::ifstream file(input_path);
    if(!file.is_open())
        throw "baaad tripp";
    std::getline(file, line);
    while(std::getline(file,line)){
        char *cstr = new char[line.size() + 1];
        std::strcpy(cstr, line.c_str());
        char *key = strtok(cstr,"|");
        char *value = strtok(NULL,"|");
        // std::cout << '\'' << key <<'\'' << value << '\'' << std::endl;
        float float_v = (float)std::strtof(value,NULL);
        if(!check_data(key,3) ||  !check_data(value,2) || !check_date(key) )
            std::cerr << "invalid data";
        if(key && value)
            print(float_v,key);
        else if( strtok(NULL,"|") != NULL){
            delete[] cstr;
            std::cerr << "vadeidheibd";
        }else{
            delete[] cstr;
            std::cerr << "yazbiii";
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
            std::cerr << "nigatiiiiiiivvvv ya zbi" << std::endl;
            return false;
            // throw std::bad_exception();
        }
        else if(!isdigit(nbr[i]) && nbr[i] != ignor && nbr[i] != ' ' )
            return false;
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
            // std::cout << '\'' << value << '\'' << std::endl;
            // std::cout << value << std::endl;
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
    // std::cout << "pass the check" << std::endl;
    return true;

}

void btc::data_(std::string path){
    data_path = path;
    std::string line;
    std::ifstream file(data_path);
    if(!file.is_open())
        throw "baaad tripp";
    std::getline(file, line);
    while(std::getline(file,line)){
        char *cstr = new char[line.size() + 1];
        std::strcpy(cstr, line.c_str());
        char *key = strtok(cstr,",");
        char *value = strtok(NULL,",");
        if(!check_data(key,1) ||  !check_data(value,2))
            throw std::bad_exception();
        if(key && value)
            data[key] = (float)std::strtof(value,NULL);
        else if( strtok(NULL,",") != NULL){
            delete[] cstr;
            throw std::bad_exception();
        }else{
            delete[] cstr;
            throw std::bad_optional_access();
        }
        delete[] cstr;
        }
    file.close();
}

