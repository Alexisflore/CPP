#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &filename) : _filename(filename) {
    //call the function filetoMap with the file data.csv
    std::ifstream
    file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("File not found");
    filetoMap(file);
}

BitcoinExchange::~BitcoinExchange() {}

//parse the csv file and store the data in the map
void BitcoinExchange::filetoMap(std::ifstream &file) {
    //data of the csv file are date, rate
    std::string line;
    std::string date;
    double rate;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::getline(ss, date, ',');
        ss >> rate;
        _exchangeRate[date] = rate;
    }
}

//return the rate of the date in the map but if the date is not found, find the closest date
double BitcoinExchange::getRate(const std::string &date) const {
    if (_exchangeRate.find(date) != _exchangeRate.end())
        return _exchangeRate.at(date);
    std::map<std::string, double>::const_iterator it = _exchangeRate.lower_bound(date);
    if (it != _exchangeRate.begin())
        return (--it)->second;
    else {
        return it->second;
    }
}

//convert the amount of bitcoin to the currency of the date
double BitcoinExchange::convert(const std::string &date, double amount) const {
    if (amount < 0)
        throw std::runtime_error("Amount cannot be negative");
    if (amount > 1000)
        throw std::runtime_error("Amount too high");
    try {
        return amount * getRate(date);
    } catch (std::exception &e) {
        throw;
    }
}

//print the amount of bitcoin in the currency of the dates
void BitcoinExchange::printAmountforDate(const std::string &date, double amount) const {
    try {
        convert(date, amount);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }
    std::cout << date << "=> " << amount << " = " << std::fixed << std::setprecision(2) << convert(date, amount) << std::endl;
}

bool BitcoinExchange::isCorrectFormatDate(const std::string &date) const {
    if (date.size() != 11) 
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }
    if (date[5] > '1' || (date[5] == '1' && date[6] > '2')
        || (date[5] == '0' && date[6] == '0')
        || date[8] > '3' 
        || (date[8] == '3' && date[9] > '1'))
        return false;
    if (date[5] == '0' && date[6] == '2' && date[8] > '2')
        return false;
    return true;
}
//display the converted amount of bitcoin in the currency of the dates store in the .txt _filename
void BitcoinExchange::display() const {
    std::ifstream
    file(_filename);
    if (!file.is_open())
        throw std::runtime_error("File not found");
    std::string line;
    std::string date;
    double amount;
    //pass the first line
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::getline(ss, date, '|');
        if (!isCorrectFormatDate(date)) {
            std::cout << "Error: " << date << " is not a valid date" << std::endl;
            continue;
        }
        ss >> amount;
        printAmountforDate(date, amount);
    }
}