
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

std::vector<unsigned int > & PmergeMe::insert(std::vector<unsigned int > &main,std::vector<unsigned int > &pend , std::vector<unsigned int > &odds,std::vector<unsigned int > &vec){

    // std::cout << "++++++++++++ insert +++++++++" << std::endl;
    // std::cout << "the order here is " << order << std::endl;
    // std::cout << " the main in the insert" << std::endl;
    // for(vector::iterator it = main.begin();it != main.end();it++)
    //     std::cout << *it << std::endl;
    // std::cout << " the pend in the insert" << std::endl;
    // for(vector::iterator it = pend.begin();it != pend.end();it++)
    //     std::cout << *it << std::endl;
    // std::cout << " the odds in the insert" << std::endl;
    // for(vector::iterator it = odds.begin();it != odds.end();it++)
    //     std::cout << *it << std::endl;
    
    // make a copy of the main 
    std::cout << "here " << std::endl;
    vector::iterator copy_it ;
    vector main_copy;
    main_copy.insert(main_copy.end(),main.begin(),main.end());
    std::cout << "here 1" << std::endl;

    if(pend.size() == 1){
        copy_it = std::upper_bound(main_copy.begin(),main_copy.end() - 1,*pend.begin());
        main.insert(main.begin() + (copy_it - main_copy.begin()),*pend.begin());
        main_copy.insert(copy_it,*pend.begin());
    std::cout << "here 2" << std::endl;

    }else if(pend.size() > 1){
        size_t jc = 3;
        size_t count = 0;
        size_t idx ;
        size_t decrease ;
        std::cout << "here 3" << std::endl;
        while(!pend.empty()){
            std::cout << "zeb 1" << std::endl;

            idx = Jacobsthal(jc) - Jacobsthal(jc - 1);
            if(idx > pend.size())
                idx = pend.size();
            decrease = 0;
            std::cout << "zeb 2" << std::endl;
            while(idx){
            std::cout << "zeb 3" << std::endl;
                std::cout << idx << std::endl;        
                Jacobsthal(jc + count ) - decrease <= main_copy.size() ? copy_it = main_copy.begin() + Jacobsthal(jc + count ) - decrease : copy_it = main_copy.end(); 
                
                copy_it = std::upper_bound(main_copy.begin(),copy_it,*(pend.begin() + idx - 1));
                
                main.insert(main.begin() + (copy_it - main_copy.begin() ),*(pend.begin() + idx - 1));
                
                std::cout << "zeb 4" << std::endl;
                
                main_copy.insert(copy_it,*(pend.begin() + idx - 1));
                
                std::cout << "zeb 5" << std::endl;
                
                pend.erase(pend.begin() + idx - 1 ,pend.begin() + idx);
                
                idx--;
                decrease++;
                count++;
            }

            jc++;
        }
    }
    if(!odds.empty())
    {
        copy_it = std::upper_bound(main_copy.begin(),main_copy.end(),*odds.begin());
        main.insert(main.begin() + (copy_it - main_copy.begin()),*odds.begin());
    }
    for(vector::iterator i = vec.begin(); i != vec.end(); i++)
        main.push_back(*i);
    for(vector::iterator it = main.begin();it != main.end();it++)
        std::cout << *it << std::endl;
    return main;
}

void PmergeMe::sort_vector(std::vector<unsigned int > &vec){
    std::cout << "sort " << std::endl;
    static int order = 1;
    int unit_size = vec.size() / order;
    if(unit_size < 2){
        std::cout << "break here " << std::endl;
        for (vector::iterator it = vec.begin();it != vec.end();it++)
            std::cout << *it << " " ;
        std::cout << std::endl;
        return ;}
    int  is_odd =  unit_size % 2 == 1 ? 1 : 0; 
    vector::iterator start = vec.begin() ;
    vector::iterator end = vec.begin() + ((order * unit_size) - (is_odd * order));
    for (vector::iterator it = start ; it != end ; it += (order * 2))
        if(*(it + (order - 1)) > *(it + ((order * 2 ) - 1)))
            for(int i = 0 ; i < order ; i++)
                std::swap(*(it + i),*(it + i + order ));
    order *= 2;
    sort_vector(vec);
    order /= 2;
    // order += 2;
    vector main;
    vector pend;
    vector odd_elm;
    vector left;
    main.push_back(*(start + order - 1));
    main.push_back(*(start + order * 2 - 1));
    for(vector::iterator it = start + order * 2 ;it != end; it += order){
        for(vector::iterator i = it ;i != it + order - 1 ;i++ )
            left.push_back(*i);
        pend.push_back(*(it + order - 1));
        it += order;
        for(vector::iterator i = it ;i != it + order - 1 ;i++ )
            left.push_back(*i);
        main.push_back(*(it + order - 1));
    }
    for (vector::iterator it = end ; it != vec.end();it++)
        odd_elm.push_back(*it);
    std::cout << "the main "<< std::endl;
    for(vector::iterator it = main.begin();it != main.end();it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "the pend "<< std::endl;
    for(vector::iterator it = pend.begin();it != pend.end();it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "the odds "<< std::endl;
    for(vector::iterator it = odd_elm.begin();it != odd_elm.end();it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "the lefts "<< std::endl;
    for(vector::iterator it = left.begin();it != left.end();it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    // std::cout << "here we go again :) " << std::endl;
    if(!odd_elm.empty() || !pend.empty())
       vec =  insert(main,pend,odd_elm,left);
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
    // for(std::vector<unsigned int >::iterator it = vec.begin();it != vec.end();it++)
    //     std::cout << *it << std::endl;


}

PmergeMe::PmergeMe(){
    
}

PmergeMe::~PmergeMe(){
    
}