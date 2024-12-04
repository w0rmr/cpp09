#include <iostream>
#include <map>
#include <string>

class btc {
    private:
        std::string data_path;
        std::string input_path;
        std::map<std::string ,std::string > data;
        bool check_errors(void);
        void parse_file(void);
        void add_to_data(std::string line);
    public:
        btc();
        void data_(std::string path);
        void input_(std::string input);
        btc(std::string file_path);
        ~btc();
};

std::ostream &operator<<(std::ostream &o , btc &BTC);