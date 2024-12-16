
#include "PmergeMe.hpp"
#include <algorithm>
void PmergeMe::args(std::string args[]){

}

int PmergeMe::time_vector(void){
    return 0;
}

int PmergeMe::time_deque(void){
    return 0;
}

bool comp_pairs(const std::pair<unsigned int , unsigned int>  &a , const std::pair<unsigned int , unsigned int>  &b){
    return (a.second < b.second );
}

// binary search !!! https://www.geeksforgeeks.org/binary-search/
//https://www.geeksforgeeks.org/johnsons-algorithm/
// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91

//https://www.geeksforgeeks.org/binary-search/
//https://en.wikipedia.org/wiki/Binary_search
//https://en.wikipedia.org/wiki/Merge-insertion_sort


// https://miro.com/app/board/uXjVNXhGDgk=/
#include <cmath>
int Jacobsthal(int k){
     return round((pow(2, k + 1) + pow(-1, k)) / 3);

}

bool comp(std::vector<unsigned int >::iterator &a,std::vector<unsigned int >::iterator &b){
    return (*a > *b);
}

std::vector<unsigned int > PmergeMe::sort_vector(std::vector<unsigned int > &vec){
    static int order = 1;
    int unit_size = vec.size() / order;
    if(unit_size < 2){
        std::cout << "the stack at the end : " << std::endl;
        for (vector::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        return vec;}
    int  is_odd =  unit_size % 2 == 1 ? 1 : 0; 
    vector::iterator start = vec.begin() ;
    vector::iterator end = vec.begin() + ((order * unit_size) - (is_odd * order));
    for (vector::iterator it = start ; it != end ; it += (order * 2))
        if(*(it + (order - 1)) > *(it + ((order * 2 ) - 1)))
            for(int i = 0 ; i < order ; i++)
                std::swap(*(it + i),*(it + i + order ));
    order *= 2;
    vec = sort_vector(vec);
    order /= 2;
    vector main;
    vector pend;
    main.push_back(*(start + order - 1));
    main.push_back(*(start + order * 2 - 1));
    for(vector::iterator it = start + order * 2 ;it != end; it += order){
        pend.push_back(*(it + order - 1));
        it +=order;
        main.push_back(*(it + order - 1));
    }
    int k = 1;
    int jacobsthal_nbr  = Jacobsthal(k);
    int inserted_nbr = 0;
    while (1){
        k++;
        int cur_jacobsthal = Jacobsthal(k);
        int dif = cur_jacobsthal - jacobsthal_nbr;
        std::cout << cur_jacobsthal << std::endl;
        int offset = 0;
        if(dif > main.size())
            break;
        vector::iterator p_it = pend.begin() + dif - 1;
        vector::iterator bound_it = main.begin() + cur_jacobsthal + inserted_nbr;
        std::cout << "the dif " << dif  << "k = " << k << std::endl;
        int i = 0;
        while(i){
                vector::iterator idx = std::upper_bound(main.begin(),bound_it,*p_it);
                vector::iterator inserted = main.insert(idx,*p_it);
                i--;
                p_it = pend.erase(p_it);
                p_it--;
                offset += ((inserted - main.begin()) == cur_jacobsthal + inserted_nbr);
                bound_it = main.begin() + (cur_jacobsthal + inserted_nbr - offset  );
        }
        jacobsthal_nbr = cur_jacobsthal;
        inserted_nbr += dif;
    }
    
    return vec;
}

std::deque<unsigned int > PmergeMe::sort_deque(std::deque<unsigned int > &vec){
    return vec;
}

int count_word_and_check(std::string &str){
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


PmergeMe::PmergeMe(int ac , char **av){
    std::string args_string ; 
    for (int i = 1 ;i < ac ;i++){
        args_string += av[i] ;
        if(av[i] != NULL)
            args_string += " ";   
    }
    // std::cout << args_string << std::endl;
    std::istringstream ss(args_string);
    unsigned int  n;
    while(ss >> n){
        // std::cout << "uuu" << n << "uuuuu" << std::endl;
       deque_.push_back(n);
       vector_.push_back(n);
    }
    if(vector_.size() != count_word_and_check(args_string))
        throw "bad trip";
    sort_vector(vector_);

}

PmergeMe::PmergeMe(){
    
}

PmergeMe::~PmergeMe(){
    
}