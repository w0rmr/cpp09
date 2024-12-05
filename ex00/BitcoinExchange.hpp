#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
// #include <string>

class btc {
    private:
        std::string data_path;
        std::string input_path;
        std::map<std::string ,float > data;
        bool check_errors(void);
        void parse_file(void);
        void print(void);
        void add_to_data(std::string);
        bool check_data(std::string data, int order);
        bool isdigit_(std::string nbr);
        bool isdigit_(std::string nbr,char ignor);
    public:
        btc();
        void data_(std::string path);
        void input_(std::string input);
        btc(std::string file_path);
        ~btc();
};

std::ostream &operator<<(std::ostream &o , btc &BTC);