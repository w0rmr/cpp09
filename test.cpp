#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform binary search and insert element into sorted vector
void binaryInsert(std::vector<int>& sorted, int value) {
    int left = 0;
    int right = sorted.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (sorted[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    sorted.insert(sorted.begin() + left, value);
}

// Comparison function for sorting pairs by their larger value
bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}



// Recursive FJMI sort function
std::vector<int> fjmiSort(std::vector<int>& arr) {
    if (arr.size() <= 1) return arr;

    // Step 1: Handle straggler if array size is odd
    bool hasStraggler = arr.size() % 2 != 0;
    int straggler = 0;
    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    // Step 2: Create pairs
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
    }

    // Step 3: Sort each pair
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first > pairs[i].second) {
            std::swap(pairs[i].first, pairs[i].second);
        }
    }

    // Step 4: Sort pairs by their larger value
    std::sort(pairs.begin(), pairs.end(), comparePairs);

    // Step 5: Create S and pend arrays
    std::vector<int> S, pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        S.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }

    // Step 6: Recursively sort S
    S = fjmiSort(S);

    // Step 7: Insert elements of pend into S using binary search
    for (size_t i = 0; i < pend.size(); ++i) {
        binaryInsert(S, pend[i]);
    }

    // Step 8: Insert straggler if it exists
    if (hasStraggler) {
        binaryInsert(S, straggler);
    }

    return S;
}
#include <sstream>
int count_word(std::string &str){
    int w = 0;
    for(int i = 0 ; str[i] != '\0' ; i++)
    {
        if(str[i] != ' ' && str[i] != '\0'){
            w++;
            while(str[i] != ' ' && str[i] != '\0')
                i++;}
    }
    return w;
}
int main(int ac , char **av) {
    std::vector<int> vec;
    std::string line ;
    for(int i = 1 ; av[i] ; i++)
    {
        line += av[i];
        if(av[i + 1])
            line += " ";
    }
    std::cout << "line = " << line << std::endl;
    std::cout << "count " << count_word(line);
    std::istringstream ss(line);
    int nbr ;
    while(ss >> nbr)
        vec.push_back(nbr);

    std::vector<int> sortedVec = fjmiSort(vec);

    std::cout << "Sorted Vector: ";
    for (int i = 0; i < sortedVec.size(); ++i) {
        std::cout << sortedVec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
