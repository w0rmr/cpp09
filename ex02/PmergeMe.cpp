
#include "PmergeMe.hpp"
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

std::vector<unsigned int > PmergeMe::sort_vector(std::vector<unsigned int > &vec){
    if(vec.size() % 2 != 0){
        unsigned int gold_zeb = vec[vec.size() - 1];
        std::cout << gold_zeb << std::endl;
        vec.pop_back();
    }
    pair pairs ;
    for (vector::iterator it = vec.begin();it != vec.end() ;it+=2)
        if(*it && *(it + 1))
            pairs.push_back(std::make_pair(*it,*(it + 1)));

    std::cout << "befor sorting !" << std::endl;
    
    for(pair::iterator it = pairs.begin(); it != pairs.end() ; it++ )
        std::cout << it->first << " - " << it->second << std::endl;

    for(pair::iterator it = pairs.begin(); it != pairs.end() ; it++){
        if(it->first < it->second)
            std::swap(it->first,it->second);
    }
    
    std::sort(pairs.begin(),pairs.end(),comp_pairs);
    
    std::cout << "after sorting ! " << std::endl;
    for(pair::iterator it = pairs.begin(); it != pairs.end() ; it++ )
        std::cout << it->first << " - " << it->second << std::endl;
    
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
       deq.push_back(n);
       vec.push_back(n);
    }
    if(vec.size() != count_word_and_check(args_string))
        throw "bad trip";
    sort_vector(vec);

}

PmergeMe::PmergeMe(){
    
}

PmergeMe::~PmergeMe(){
    
}