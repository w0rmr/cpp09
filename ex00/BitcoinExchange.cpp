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
void btc::print(void){

}

void btc::parse_file(void){
}

bool btc::check_date(std::string date){
    std::cout << "the date is => "<< date << std::endl;
    // bad trip had l code 
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
        char *key = strtok(cstr,",");
        char *value = strtok(NULL,",");
        if(!check_data(key,1) ||  !check_data(value,2) || ~check_date(key) )
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
        if(!isdigit(nbr[i]))
            return false;
    return true;

}

bool btc::isdigit_(std::string nbr,char ignor){
    for(unsigned long i = 0 ; i < nbr.size() ;i++)
        if(!isdigit(nbr[i]) && nbr[i] != ignor)
            return false;
    return true;

}

bool btc::check_data(std::string data,int order){
    if (order == 1){ 
        if(data.size() > 10)
            return false;
        else if(data[4] != data[7] &&  data[7] != '-')
            return false ;
        char *cstr = new char[data.size() + 1];
        cstr = std::strcpy(cstr,data.c_str());
        char * value = strtok(cstr,"-");
        while (value)
        {
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

