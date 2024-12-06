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
// 2011-01-03 => 3 = 0.9
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.32
// Error: not a positive number.
// Error: bad input => 2001-42-42
// 2012-01-11 => 1 = 7.1
// Error: too large a number.