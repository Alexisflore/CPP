#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./pmergeme <string>" << std::endl;
        exit(1);
    }
    for (int i = 1; i < argc; i++)
    {
        if (i != 1)
            _str += " ";
        _str += argv[i];
    }
    try {
			timeval start, end;
			gettimeofday(&start, NULL);
			_arrList = argsToList(_str);
			gettimeofday(&end, NULL);
			long seconds = end.tv_sec - start.tv_sec;
			long microseconds = end.tv_usec - start.tv_usec;
			_timeList += seconds * 1000000.0 + microseconds;
			gettimeofday(&start, NULL);
			_arrVector = argsToVector(_str);
			gettimeofday(&end, NULL);
			seconds = end.tv_sec - start.tv_sec;
			microseconds = end.tv_usec - start.tv_usec;
			_timeVector += seconds * 1000000.0 + microseconds;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(1);
    }
    SortVector();
    SortList();
    display();
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
    *this = src;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::display()
{
    std::cout << "Before: ";
    // if (_str.size() > 15)
	// 	std::cout << _str.substr(0, 15) << "[...]" << std::endl;
	// else
	// 	std::cout << _str << std::endl;
	std::cout << _str << std::endl;
    std::cout << "After: ";
    displayVector();
    // displayList();
    std::cout << "Time to process a range of " << _arrVector.size() << " elements " << "with std::vector<int>: " << std::fixed << std::setprecision(5) << _timeVector << "us" << std::endl;
    std::cout << "Time to process a range of " << _arrList.size() << " elements " << "with std::list<int>: " << std::fixed << std::setprecision(5) << _timeList << "us" << std::endl;
}

std::list<int> PmergeMe::argsToList(std::string str)
{
    std::list<int> list;
    std::istringstream iss(str);
    std::string token;
    int nbr;
    while (std::getline(iss, token, ' '))
    {
        try {
            nbr = atoi(token.c_str());
            if (nbr < 0)
                throw std::invalid_argument("Negative number");
            list.push_back(nbr);
        } catch (std::exception &e) {
            throw std::invalid_argument("Invalid number");
        }
    }
    if (isDuplicate(list))
        throw std::invalid_argument("Duplicate number");
    return list;
}

std::vector<int> PmergeMe::argsToVector(std::string str)
{
    std::vector<int> vector;
    std::istringstream iss(str);
    std::string token;
    while (std::getline(iss, token, ' '))
    {
        try {
            for (unsigned long k = 0; k < token.size(); k++)
            {
                if (token[k] < '0' || token[k] > '9')
                    throw std::invalid_argument("Invalid number");
            }
            vector.push_back(atoi(token.c_str()));
        } catch (std::exception &e) {
            throw std::invalid_argument("Invalid number");
        }
    }
    if (isDuplicate(vector))
        throw std::invalid_argument("Duplicate number");
    return vector;
}

void PmergeMe::InsertionSort(std::vector<int> &arr)
{
    unsigned long i;
    int key, j;
    for (i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::InsertionSort(std::list<int> &arr)
{
    std::list<int> sorted;
    for (std::list<int>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        std::list<int>::iterator it2 = sorted.begin();
        while (it2 != sorted.end() && *it2 < *it)
            it2++;
        sorted.insert(it2, *it);
    }
    arr = sorted;
}

void PmergeMe::MergeInsertionSort(std::vector<int> &arr)
{
    // if (arr.size() <= 10)
    // {
    //     InsertionSort(arr);
    //     return;
    // }
	if (arr.size() == 1)
		return;
    std::vector<int> left;
    std::vector<int> right;
    int middle = arr.size() / 2;
    for (int i = 0; i < middle; i++)
        left.push_back(arr[i]);
    for (unsigned long i = middle; i < arr.size(); i++)
        right.push_back(arr[i]);
    MergeInsertionSort(left);
    MergeInsertionSort(right);
    arr = Merge(left, right);
}

std::vector<int> PmergeMe::Merge(std::vector<int> &left, std::vector<int> &right)
{
    std::vector<int> result;
    while (left.size() > 0 && right.size() > 0)
    {
        if (left.front() <= right.front())
        {
            result.push_back(left.front());
            left.erase(left.begin());
        }
        else
        {
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }
    while (left.size() > 0)
    {
        result.push_back(left.front());
        left.erase(left.begin());
    }
    while (right.size() > 0)
    {
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

void PmergeMe::MergeInsertionSort(std::list<int> &arr)
{
    if (arr.size() == 1)
        return;
    std::list<int> left;
    std::list<int> right;
    int middle = arr.size() / 2;
    int i = 0;
    for (std::list<int>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        if (i < middle)
            left.push_back(*it);
        else
            right.push_back(*it);
        i++;
    }
    MergeInsertionSort(left);
    MergeInsertionSort(right);
    arr = Merge(left, right);
}

std::list<int> PmergeMe::Merge(std::list<int> &left, std::list<int> &right)
{
    std::list<int> result;
    while (left.size() > 0 && right.size() > 0)
    {
        if (left.front() <= right.front())
        {
            result.push_back(left.front());
            left.pop_front();
        }
        else
        {
            result.push_back(right.front());
            right.pop_front();
        }
    }
    while (left.size() > 0)
    {
        result.push_back(left.front());
        left.pop_front();
    }
    while (right.size() > 0)
    {
        result.push_back(right.front());
        right.pop_front();
    }
    return result;
}

void PmergeMe::displayVector()
{
	std::stringstream ss;
    std::string str;
    for (size_t i = 0; i < _arrVector.size(); i++)
    {
        if (i != 0)
            ss << " ";
        ss << _arrVector[i];
    }
	str = ss.str();
	// if (str.size() > 12)
	// 	std::cout << str.substr(0, 15) << "[...]" << std::endl;
	// else
    // 	std::cout << str << std::endl;
	std::cout << str << std::endl;
}
void PmergeMe::displayList()
{
    std::string str;
	std::stringstream ss;
    for (std::list<int>::iterator it = _arrList.begin(); it != _arrList.end(); it++)
    {
        if (it != _arrList.begin())
			ss << " ";
		ss << *it;
	}
	str = ss.str();
    std::cout << str << std::endl;
}
void PmergeMe::SortVector()
{
	timeval start, end;
	gettimeofday(&start, NULL);
    MergeInsertionSort(_arrVector);
	gettimeofday(&end, NULL);
	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	_timeVector += seconds * 1000000.0 + microseconds;
}

void PmergeMe::SortList()
{
	timeval start, end;
	gettimeofday(&start, NULL);

	MergeInsertionSort(_arrList);

	gettimeofday(&end, NULL);
	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	_timeList += seconds * 1000000.0 + microseconds;
}

bool PmergeMe::isDuplicate(std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
                return true;
        }
    }
    return false;
}

bool PmergeMe::isDuplicate(std::list<int> &arr)
{
    for (std::list<int>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        for (std::list<int>::iterator it2 = it; it2 != arr.end(); it2++)
        {
            if (it != it2 && *it == *it2)
                return true;
        }
    }
    return false;
}
