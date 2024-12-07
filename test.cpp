#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdexcept>
#include <regex>

// Function to split a string by spaces
std::vector<std::string> split(const std::string& str) {
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    try {
        std::stack<int> mystack;
        std::string expr;
        std::cout << "Enter expression with space between numbers and operators: ";
        std::getline(std::cin, expr);

        // Remove extra spaces and split the expression into elements
        expr = std::regex_replace(expr, std::regex(" +"), " ");
        expr = std::regex_replace(expr, std::regex("^ +| +$"), "");
        std::vector<std::string> elements = split(expr);

        for (const std::string& x : elements) {
            if (x == "+") {
                int n1 = mystack.top(); mystack.pop();
                int n2 = mystack.top(); mystack.pop();
                int n3 = n2 + n1;
                mystack.push(n3);
            } else if (x == "-") {
                int n1 = mystack.top(); mystack.pop();
                int n2 = mystack.top(); mystack.pop();
                int n3 = n2 - n1;
                mystack.push(n3);
            } else if (x == "*") {
                int n1 = mystack.top(); mystack.pop();
                int n2 = mystack.top(); mystack.pop();
                int n3 = n2 * n1;
                mystack.push(n3);
            } else if (x == "//" || x == "/") {
                int n1 = mystack.top(); mystack.pop();
                int n2 = mystack.top(); mystack.pop();
                if (n1 == 0) {
                    throw std::runtime_error("division by zero");
                }
                int n3 = (x == "//") ? n2 / n1 : n2 / n1;
                mystack.push(n3);
            } else {
                mystack.push(std::stoi(x));
            }
        }
        std::cout << "Result: " << mystack.top() << std::endl;
        mystack.pop();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}