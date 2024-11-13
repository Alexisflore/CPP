#include "RPN.hpp"

RPN::RPN(std::string const &str)
{
    _str = str;
}

RPN::RPN(RPN const &src)
{
    *this = src;
}

RPN::~RPN()
{
}

void RPN::_calculate()
{
    long int1 = 0;
    long int2 = 0;
    std::istringstream iss(_str);
    std::string token;
    while (std::getline(iss, token, ' '))
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_array.size() < 2)
                throw std::invalid_argument("Invalid expression");
            //delete the two last elements of the array and store them in int1 and int2
            int1 = _array.top();
            _array.pop();
            int2 = _array.top();
            _array.pop();
            if (token == "+")
            {
                _array.push(int2 + int1);
            }
            else if (token == "-")
            {
                _array.push(int2 - int1);
            }
            else if (token == "*")
            {
                _array.push(int2 * int1);
            }
            else if (token == "/")
            {
                _array.push(int2 / int1);
            }
        }
        else
        {
			if (token[0] != '-' && !std::isdigit(token[0]) && token[0] != '+')
			{
				throw std::invalid_argument("Invalid number");
			}
			for (size_t i = 1; i < token.size(); i++)
			{
				if (!std::isdigit(token[i]))
					throw std::invalid_argument("Invalid number");
			}
			long long value;
			//check overflow
			std::istringstream(token) >> value;
			if (value > INT_MAX || value < INT_MIN)
			{
				throw std::overflow_error("Integer overflow");
			}
			_array.push(value);
        }
    }
    if (_array.size() != 1)
        throw std::invalid_argument("Invalid expression");
    _result = _array.top();
}

void RPN::display()
{
    try {
        _calculate();
        std::cout << _result << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
