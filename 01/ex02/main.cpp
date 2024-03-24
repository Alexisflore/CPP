#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";

    char *ptr = &str[0];
    std::string& ref = str;

    //adress of the string
    std::cout << "adress of ptr: " << (void*)ptr << std::endl;
    std::cout << "adress of ref: " << &ref << std::endl;
    std::cout << "adress of str: " << &str << std::endl;

    //value of the string
    std::cout << "value of ptr: " << ptr << std::endl;
    std::cout << "value of ref: " << ref << std::endl;
    std::cout << "value of str: " << str << std::endl;

    return 0;
}