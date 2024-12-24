#pragma once 

#include <string>
#include <iostream>
#include <exception>
#include <stack>
#include <algorithm>
#include <sstream>

class RPN {
    private:
        std::stack<int> Stack;
        void yaslam(char op);
        bool input_check(std::string &inp);
    public:
        bool empty(void);
        size_t size(void);
        int pop();
        RPN();
        RPN &operator=(RPN &rpn);
        RPN(RPN &rpn);
        RPN(std::string args);
        // ~RPN();

};
std::ostream &operator<<(std::ostream &os ,RPN &rpn);