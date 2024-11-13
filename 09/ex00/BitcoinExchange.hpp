#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

class BitcoinExchange {
    public:
        BitcoinExchange(const std::string &filename);
        ~BitcoinExchange();
        void printAmountforDate(const std::string &date, double amount) const;
        void display() const;
    private:
        std::string _filename;
        std::map<std::string, double> _exchangeRate;
        void filetoMap(std::ifstream &file);
        double getRate(const std::string &date) const;
        double convert(const std::string &date, double amount) const;
        bool isCorrectFormatDate(std::string &date) const;
		bool isCorrectAmount(std::string &amount) const;
};
