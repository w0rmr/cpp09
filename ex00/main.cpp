#include "BitcoinExchange.hpp"

int main(int ac , char **av){
    try{
        if(ac == 2){
            btc bt;
            bt.input_(av[1]);
            bt.data_("./data.csv");
            std::cout << bt << std::endl;
        }else
            throw std::bad_optional_access();
    }catch(...){
        std::cerr << "baaaad tripppp " << std::endl;
    }
    return 0;
}