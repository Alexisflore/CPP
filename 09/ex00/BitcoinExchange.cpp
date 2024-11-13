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
	//pass the first line
	std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream ss(line);
		std::string s = ss.str();
		std::string amountStr = s.substr(s.find(',') + 1);
		if (!isCorrectAmount(amountStr)) {
			std::cout << "Error: " << amountStr << " is not a valid amount" << std::endl;
			continue;
		}
        std::getline(ss, date, ',');
		if (!isCorrectFormatDate(date)) {
			std::cout << "Error: " << date << " is not a valid date" << std::endl;
			continue;
		}
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

bool BitcoinExchange::isCorrectFormatDate(std::string &date) const {
	int start = 0;
	while (date[start] != '\0' && date[start] == ' ')
		start++;
	int end = date.size() - 1;
	while (end >= 0 && date[end] == ' ')
		end--;
	if (start > end)
		return false;
	date = date.substr(start, end - start + 1);
    if (date.size() != 10)
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

bool BitcoinExchange::isCorrectAmount(std::string &amount) const {
	int start = 0;
	bool point = false;
	while (amount[start] != '\0' && amount[start] == ' ')
		start++;
	int end = amount.size() - 1;
	while (end >= 0 && amount[end] == ' ')
		end--;
	if (start > end)
		return false;
	amount = amount.substr(start, end - start + 1);
	if (amount[0] != '-' && !std::isdigit(amount[0]) && amount[0] != '+')
		return false;
	//create a string until the first point
	std::string s = amount.substr(0, amount.find('.'));
	if ((s.size() > 10 && std::isdigit(s[0])) || (s.size() > 11 && (s[0] == '-' || s[0] == '+')))
		return false;
	for (size_t i = 1; i < amount.size(); i++)
	{
		if (amount[i] == '.')
		{
			if (point)
				return false;
			if (!std::isdigit(amount[i - 1]) || !std::isdigit(amount[i + 1]))
				return false;
			point = true;
			continue;
		}
		else if (!std::isdigit(amount[i]))
			return false;
	}
	return true;
}

//display the converted amount of bitcoin in the currency of the dates store in the .txt _filename
void BitcoinExchange::display() const {
    std::ifstream
    file(_filename.c_str());
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
		// std::istringstream(ss) >> amount;
		// //
		std::string s = ss.str();
		std::string amountStr = s.substr(s.find('|') + 1);
		if (!isCorrectAmount(amountStr)) {
			std::cout << "Error: " << amountStr << " is not a valid amount" << std::endl;
			continue;
		}
		amount = static_cast<double>(atof(amountStr.c_str()));
        printAmountforDate(date, amount);
    }
}
