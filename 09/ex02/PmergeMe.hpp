#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <sstream>
#include <chrono>
#include <ctime>
#include <time.h>

class PmergeMe {
    public:
        PmergeMe(int argc, char **argv);
        ~PmergeMe();
        PmergeMe(PmergeMe const &src);
        void display();
    private:
        std::vector<int> _arrVector;
        std::list<int> _arrList;
        std::list<int> argsToList(std::string str);
        std::vector<int> argsToVector(std::string str);
        void InsertionSort(std::vector<int> &arr);
        void InsertionSort(std::list<int> &arr);
        void MergeInsertionSort(std::vector<int> &arr);
        void MergeInsertionSort(std::list<int> &arr);
        std::vector<int> Merge(std::vector<int> &left, std::vector<int> &right);
        std::list<int> Merge(std::list<int> &left, std::list<int> &right);
        void SortVector();
        void SortList();
        void displayVector();
        void displayList();
        double _timeVector;
        double _timeList;
        std::string _str;
};