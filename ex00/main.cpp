#include "BitcoinExchange.hpp"

int main(int ac , char **av){
    try{
        if(ac == 2){
            btc bt(av[1],"./data.csv");
        
            std::cout << bt << std::endl;
        }else
            throw std::bad_optional_access();
    }catch(...){
        std::cerr << "baaaad tripppp " << std::endl;
    }
    return 0;
}