#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
// #include <string>

class btc {
    private:
        std::string data_path;
        std::string input_path;
        std::map<std::string ,float > data;
        bool check_date(std::string date);
        void check_and_print(void);
        void parse_file(void);
        void print(float rate , std::string date); 
        bool check_year(unsigned int year);
        bool check_month(unsigned int month);
        bool check_day(unsigned int day ,unsigned int month , unsigned int year);
        bool isleap(unsigned int year);
        void err();
        bool check_data(std::string data, int order);
        bool isdigit_(std::string nbr);
        std::string err_str;
        bool isdigit_(std::string nbr,char ignor);
    public:
        btc();
        void data_(std::string path);
        void input_(std::string input);
        btc(std::string file_path,std::string csv_path);
        ~btc();
};

std::ostream &operator<<(std::ostream &o , btc &BTC);