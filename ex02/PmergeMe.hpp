#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <ctime>
#include <iomanip>

template <typename Container>
class PmergeMe {
    Container container;
        public:
        typedef typename Container::value_type ValueType;
        typedef typename Container::iterator Iterator;
        PmergeMe();
        PmergeMe(char **av);
        void sort_time();
        void sort();
        typename Container::iterator begin();
        typename Container::iterator end();
    private:
        time_t start_;
        time_t end_;
        float time();
        int Jacobsthal(int k);
        size_t count_word_and_check(std::string &str);    
        void sort(Container &vec);
        std::string container_type();
        void insert(Container &main, Container &pend, ValueType odd, Container &left, Container &vec, bool is_odd, int order);
};

template <typename Container>
std::ostream& operator<<(std::ostream &os, const PmergeMe<Container> &obj);
#include "PmergeMe.tpp"

#endif