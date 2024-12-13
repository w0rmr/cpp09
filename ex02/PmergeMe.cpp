
#include "PmergeMe.hpp"
#include "algorithm"
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




std::vector<unsigned int > PmergeMe::sort_vector(std::vector<unsigned int > &vec){
    static int order = 1;
    int unit_size = vec.size() / order;
    if(unit_size < 2){
        return vec;
    }
    int  is_odd =  unit_size % 2 == 1 ? 1 : 0; 
    std::vector<unsigned int >::iterator start = vec.begin() ;
    std::vector<unsigned int >::iterator end = vec.begin() + ((order * unit_size) - (is_odd * order));
    for (vector::iterator it = start ; it != end ; it += (order * 2))
    {
        if(*(it + (order - 1)) > *(it + ((order * 2 ) - 1)))
            std::swap(*(it + (order - 1)),*(it + ((order * 2 ) - 1)));
    }
    order *= 2;
    vec = sort_vector(vec);
    
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