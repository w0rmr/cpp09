
#include "PmergeMe.hpp"

// bool PmergeMe::is_a_less_than_b(unsigned int a , unsigned int b){
//     return a > b;
// }

// void PmergeMe::fill_and_sort(unsigned int a , unsigned int b){
//     (void) a;
//     (void) b;
    
// }

// void PmergeMe::sort(){
    
// }

int proccess_arg(std::string arg1){
    return(arg1.empty());

}

PmergeMe::PmergeMe(int ac , char **av){
    std::string args_string ; 
    for (int i = 1 ;i < ac ;i++){
        args_string += av[i] ;
        if(av[i] != NULL)
            args_string += " ";   
    }
    std::istringstream ss(args_string);
}

PmergeMe::PmergeMe(){
    
}

PmergeMe::~PmergeMe(){
    
}