#include "PmergeMe.hpp"
int main(int ac , char **av){
    try{
        if(ac > 2){
            PmergeMe<std::deque<int > > Deque(av);
            PmergeMe<std::vector<int > > Vector(av);

            std::cout << "Before: " << Deque << std::endl;
            Deque.sort();
            Vector.sort();
            std::cout << "After: " << Deque << std::endl;
            
            Deque.sort_time();
            Vector.sort_time();

        }else 
            throw "bad trip";
    }catch(...){
        std::cerr << "bad trip " << std::endl;
    }
    return 0;
}