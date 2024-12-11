#pragma once 
#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <sstream>
class PmergeMe {
    private:
        std::vector<unsigned int> vec;
        std::deque<unsigned int> deq;
    public:
        PmergeMe();
        int time_vector(void);
        int time_deque(void);
        
        PmergeMe(int ac , char **av);
        ~PmergeMe();
};