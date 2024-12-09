
#include "PmergeMe.hpp"

bool PmergeMe::is_a_less_than_b(unsigned int a , unsigned int b){
    return a > b;
}

void PmergeMe::fill_and_sort(unsigned int a , unsigned int b){
    (void) a;
    (void) b;
    
}

void PmergeMe::sort(){
    
}

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
    unsigned int s1 ,s2; 
    
    while(ss >> s1 >> s2)
        Stack.push_back(std::pair<unsigned int , unsigned int >(s1,s2));
    
    for(std::vector<std::pair<unsigned int , unsigned int> >::iterator it = Stack.begin();it != Stack.end();it++)
        if(it->first > it->second){
            unsigned int tmp = it->first;
            it->first = it->second;
            it->second = tmp;
        }
    for(std::vector<std::pair<unsigned int , unsigned int> >::iterator it = Stack.begin();it != Stack.end();it++)
        std::cout << it->first << " "<< it->second << std::endl;
    
}

PmergeMe::PmergeMe(){
    
}

PmergeMe::~PmergeMe(){
    
}