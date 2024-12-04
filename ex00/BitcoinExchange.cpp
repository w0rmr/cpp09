#include "BitcoinExchange.hpp"
#include <exception>
btc::btc(){}
btc::~btc(){}
btc::btc(std::string file_path) :input_path(file_path){ 
    if(check_errors())
        parse_file();
    else
        throw std::bad_optional_access();
}

void btc::add_to_data(std::string line){
    


}

void btc::parse_file(void){
}

bool btc::check_errors(void){
    return true;
}

void btc::input_(std::string input){
    input_path = input;
    std::cout << "data path => " << input_path << std::endl;
}


std::ostream &operator<<(std::ostream &o , btc &BTC){
    (void) BTC;
    o << "btc\n" ;
    return o;
}

void btc::data_(std::string path){
    data_path = path;
    std::cout << "data path => " << data_path << std::endl;
}

