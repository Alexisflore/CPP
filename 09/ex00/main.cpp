#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./bitcoin_exchange <filename>" << std::endl;
        return 1;
    }
    BitcoinExchange exchange(argv[1]);
    exchange.display();
}