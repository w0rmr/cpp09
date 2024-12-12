#include "PmergeMe.hpp"
int main(int ac , char **av){
    try{
        if(ac > 2){
            PmergeMe P(ac,av);
            // std::cout << P.sort_vector() << std::endl;
            // std::cout << P.sort_deque() << std::endl;

        }else 
            throw "bad trip";
    }catch(...){
        std::cerr << "bad trip " << std::endl;
    }

}