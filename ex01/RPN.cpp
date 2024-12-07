#include "RPN.hpp"

bool check_token(std::string inp){
    if(!std::isdigit( inp[0]) && inp != "-" && inp != "+" && inp != "/" && inp != "*")
        return false;
    else 
        return true;
}
// N "1 2 *" " 2 /" " 2 * " 2 4 " - +"

void RPN::yaslam(char op){
    if(Stack.empty())
        throw std::exception();
    int n1 = Stack.top();
    Stack.pop();
    int n2 = Stack.top();
    Stack.pop();
    if(op == '*')
        Stack.push( n2 * n1);
    else if (op == '-')
        Stack.push( n2 - n1);
    else if(op == '+'){
        std::cout << "n1 " << n1  << " n2 " << n2 << std::endl; 
        std::cout << "+ yazbii " << n2 + n1 << std::endl;
        Stack.push(n2 + n1);
    }
    else if(op == '/')
    {
        if(n1 == 0){
            std::cerr << "impossible op " << n2 << " / " << n1 << std::endl;
            throw std::exception();
        }
        Stack.push(n2 / n1);
    }
}

bool RPN::input_check(std::string &inp){
    if(inp.empty())
        return false;
    char *cstr = new char[inp.size() + 1];
    cstr = std::strcpy(cstr,inp.c_str());
    char* token = std::strtok(cstr," ");
    // int order = - 1;
    while(token){
        std::string tmp = token;
        if(std::strlen(token) != 1 || !check_token(token)){
            delete[] cstr;
            return false ;
        }else{
            std::cout << token[0] << std::endl;
            char op = token[0];
            if(op == '-' || op == '+' || op == '/' || op == '*')
                yaslam(op);
            else
                Stack.push(std::stoi(token));
                
        }
        token = std::strtok(NULL," ");
    }
    delete [] cstr;
    return true ;
}

RPN::RPN(std::string args){
    char value;
    std::istringstream stream(args);
    if(!input_check(args))
        throw std::exception();
    while((stream >> value))
        Stack.push(value);
    // (void) args;
}
int RPN::pop(void){
    return Stack.pop(),Stack.top();
}

std::ostream &operator<<(std::ostream &os ,RPN &rpn){
    os << rpn.pop() << std::endl;
    return os;
}