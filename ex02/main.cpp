#include "PmergeMe.hpp"
int main(int ac , char **av){
    try{
        if(ac > 2)
            PmergeMe P(ac,av);
        else 
            throw "bad trip";
    }catch(...){
        std::cerr << "bad trip " << std::endl;
    }

}