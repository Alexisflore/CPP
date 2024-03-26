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
    _arrVector = argsToVector(_str);
    _arrList = argsToList(_str);
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
    std::cout << "Before" << std::endl;
    std::cout << _str << std::endl;
    std::cout << "After" << std::endl;
    displayVector();
    displayList();
    std::cout << "Time to process a range of " << _arrVector.size() << " elements " << "with std::vector<int>: " << _timeVector << "ms" << std::endl;
    std::cout << "Time to process a range of " << _arrList.size() << " elements " << "with std::list<int>: " << _timeList << "ms" << std::endl;
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
            nbr = std::stoi(token);
            if (nbr < 0)
                throw std::invalid_argument("Negative number");
            list.push_back(nbr);
        } catch (std::exception &e) {
            throw std::invalid_argument("Invalid number");
        }
    }
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
            vector.push_back(std::stoi(token));
        } catch (std::exception &e) {
            throw std::invalid_argument("Invalid number");
        }
    }
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
    if (arr.size() <= 10)
    {
        InsertionSort(arr);
        return;
    }
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
    if (arr.size() <= 10)
    {
        InsertionSort(arr);
        return;
    }
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
    std::string str;
    for (size_t i = 0; i < _arrVector.size(); i++)
    {
        if (i != 0)
            str += " ";
        str += std::to_string(_arrVector[i]);
    }
    std::cout << str << std::endl;
}
void PmergeMe::displayList()
{
    std::string str;
    for (std::list<int>::iterator it = _arrList.begin(); it != _arrList.end(); it++)
    {
        if (it != _arrList.begin())
            str += " ";
        str += std::to_string(*it);
    }
    std::cout << str << std::endl;
}
void PmergeMe::SortVector()
{
    std::clock_t start = std::clock();

    // Code you want to time goes here

    MergeInsertionSort(_arrVector);
    std::clock_t end = std::clock();
    _timeVector = 1000.0 * (end - start) / CLOCKS_PER_SEC;

    // std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    // std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    // _timeVector = end - start;
}

void PmergeMe::SortList()
{
    std::clock_t start = std::clock();

    // Code you want to time goes here

    MergeInsertionSort(_arrList);
    std::clock_t end = std::clock();
    _timeList = 1000.0 * (end - start) / CLOCKS_PER_SEC;

    // std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    // std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    // _timeList = end - start;
}



