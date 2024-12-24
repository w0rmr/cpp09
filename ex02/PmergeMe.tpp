#pragma once
#include "PmergeMe.hpp"
// binary search !!! https://www.geeksforgeeks.org/binary-search/
//https://www.geeksforgeeks.org/johnsons-algorithm/
// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91

//https://www.geeksforgeeks.org/binary-search/
//https://en.wikipedia.org/wiki/Binary_search
//https://en.wikipedia.org/wiki/Merge-insertion_sort

template <typename Container>
std::ostream& operator<<(std::ostream &os, PmergeMe<Container> &obj) {
        typename Container::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it) {
            os << *it << " ";
        }
        return os;
}

template <typename Container>
typename Container::iterator PmergeMe<Container>::begin(){
    return container.begin();
}

template <typename Container>
typename Container::iterator PmergeMe<Container>::end(){
    return container.end();
}

template <typename Container>
PmergeMe<Container>::PmergeMe(char **av){
    std::string args_string ;
    for (int i = 1 ;av[i] ;i++){
        args_string += av[i] ;
        if(av[i] != NULL)
            args_string += " ";   
    }
    std::istringstream ss(args_string);
    ValueType  n;
    while(ss >> n){
        if (std::find(container.begin(), container.end(), n) != container.end())
            throw std::runtime_error("Duplicate value detected");
       container.push_back(n);
       }
    if(container.size() != count_word_and_check(args_string))
        throw "bad trip";
}

template <typename Container>
size_t PmergeMe<Container>::count_word_and_check(std::string &str){
    int w = 0;
    for(int i = 0 ; str[i] != '\0' ; i++)
    {
        if(str[i] != ' ' && str[i] != '\0'){
            w++;
            while(str[i] != ' ' && str[i] != '\0')
            {
                if(!std::isdigit( str[i]) && str[i] != '+')
                    throw "bad trip";
                i++;
            }
        }
    }
    return w;
}

template <typename Container>
int PmergeMe<Container>::Jacobsthal(int k){
    return round((pow(2, k + 1) + pow(-1, k)) / 3);
}

template <typename Container>
PmergeMe<Container>::PmergeMe(){

}

template <typename Container>
void PmergeMe<Container>::insert(Container &main, Container &pend, ValueType odd, Container &left, Container &vec, bool is_odd, int order) {
    Iterator end;
    if (pend.size() == 1) {
        end = std::upper_bound(main.begin(), main.end(), *pend.begin());
        main.insert(end, *pend.begin());
    } else if (pend.size() > 1) {
        size_t jc = 3;
        size_t count = 0;
        size_t idx;
        size_t decrease;
        while (!pend.empty()) {
            idx = Jacobsthal(jc) - Jacobsthal(jc - 1);
            if (idx > pend.size())
                idx = pend.size();
            decrease = 0;
            while (idx) {
                end = main.begin();
                if (Jacobsthal(jc + count) - decrease <= main.size())
                    end = main.begin() + Jacobsthal(jc + count) - decrease;
                else 
                    end = main.end();
                end = std::upper_bound(main.begin(), end, *(pend.begin() + idx - 1));
                main.insert(end, *(pend.begin() + idx - 1));
                pend.erase(pend.begin() + idx - 1);
                idx--;
                decrease++;
                count++;
            }
            jc++;
        }
    }
    Container yaslam;
    if (is_odd) {
        end = std::upper_bound(main.begin(), main.end(), odd);
        main.insert(end, odd);
    }
    for (Iterator i = main.begin(); i != main.end(); i++) {
        Iterator it = std::find(vec.begin(), vec.end(), *i);
        yaslam.insert(yaslam.end(), it - (order - 1), it + 1);
    }
    yaslam.insert(yaslam.end(), left.begin(), left.end());
    vec = yaslam;
}
template <typename Container>
void PmergeMe<Container>::sort(){
    sort(container);
}

template <typename Container>
void PmergeMe<Container>::sort(Container &vec) {
    static int order = 1;
    if(order == 1)
        start_ = clock();
    int unit_size = vec.size() / order;
    if (unit_size < 2) return;

    bool is_odd = unit_size % 2 == 1;
    Iterator start = vec.begin();
    Iterator end = vec.begin() + ((order * unit_size) - (is_odd * order));

    for (Iterator it = start; it < end; it += (order * 2)) {
        if (*(it + (order - 1)) > *(it + ((order * 2) - 1))) {
            for (int i = 0; i < order; i++) {
                std::swap(*(it + i), *(it + i + order));
            }
        }
    }

    order *= 2;
    sort(vec);
    order /= 2;

    Container main;
    Container pend;
    ValueType odd = 0;
    Container left;

    main.push_back(*(start + order - 1));
    main.push_back(*(start + order * 2 - 1));

    for (Iterator it = start + order * 2; it < end; it += order) {
        pend.push_back(*(it + order - 1));
        it += order;
        main.push_back(*(it + order - 1));
    }

    if (is_odd) odd = *(end + order - 1);

    left.insert(left.end(), end + (order * is_odd), vec.end());

    if (is_odd || !pend.empty()) 
        insert(main, pend, odd, left, vec, is_odd, order);
    if(order == 1)
        end_ = clock();

}

template <typename Container>
void PmergeMe<Container>::sort_time() {
    float elapsedTime = time();
    std::cout << "Time to process a range of " << container.size() << " elements with " << container_type() << " : " << std::fixed << std::setprecision(6) << elapsedTime << " s" << std::endl;
}
template <typename Container>
float PmergeMe<Container>::time() {
    return static_cast<float>(end_ - start_) / CLOCKS_PER_SEC;
}

template <typename Container>
std::string PmergeMe<Container>::container_type(){
    if(typeid(container) == typeid(std::vector<typename Container::value_type>))
        return "std::vector";
    else if (typeid(container) == typeid(std::deque<typename Container::value_type>)){
        return "std::deque";
    }else if (typeid(container) == typeid(std::list<typename Container::value_type>)){
        return "std::list";
    }
    return "bad trip";
}