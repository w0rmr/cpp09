#pragma once 
#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <sstream>

class PmergeMe {
    private:
        typedef std::vector<unsigned int > vector;
        typedef std::vector<std::pair<unsigned int , unsigned int > >pair; 
    public:
        std::vector<unsigned int> vector_;
        std::deque<unsigned int> deque_;
        PmergeMe();
        void args(std::string args[]);
        int time_vector(void);
        int time_deque(void);
        void sort_vector(std::vector<unsigned int > &vec);
        std::deque<unsigned int > sort_deque(std::deque<unsigned int > &vec);
        void insert(std::vector<unsigned int > &main,std::vector<unsigned int > &pend , unsigned int odd,std::vector<unsigned int > &left,std::vector< unsigned int > &tmp ,int is_odd,int order);
        PmergeMe(int ac , char **av);
        ~PmergeMe();
};