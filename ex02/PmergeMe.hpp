#pragma once 
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
class PmergeMe {
    private:
        std::vector<std::pair<unsigned int , unsigned int > > Stack;
        bool is_a_less_than_b(unsigned int a , unsigned int b);
        void fill_and_sort(unsigned int a , unsigned int b);
        void sort();
    public:
        PmergeMe();
        PmergeMe(int ac , char **av);
        ~PmergeMe();
};