#include "RPN.hpp"
// https://youtu.be/TIu0-2mKVFQ
int main(int ac , char **av){
    try{
        if(ac == 2)
            RPN rpn(av[1]);
        else 
            throw std::exception();

    } catch(std::exception &e){
        std::cerr << "Error"<< std::endl;
    }

}