#pragma once 

#include <string>
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <sstream>

class RPN {
    private:
        std::vector< std::vector<int> > elm;
    public:
        RPN(std::string args);
        // ~RPN();

};