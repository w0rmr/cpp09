#include "RPN.hpp"

RPN::RPN(std::string args){
    char value;
    std::istringstream stream;
    int i = 0;
    while((stream >> value) && i < 3)
    {
        std::vector<int> stack;
        stack.push_back(value);
    }
    (void) args;
}
