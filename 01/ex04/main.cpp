#include <iostream>
#include <string>
#include <fstream>

void customReplace(std::string& str, const std::string& from, const std::string& to) {
    size_t startPos = 0;
    while ((startPos = str.find(from, startPos)) != std::string::npos) {
        str = str.substr(0, startPos) + to + str.substr(startPos + from.length());
        startPos += to.length();
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: filename s1 s2" << std::endl;
        return 1;
    }
    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(argv[1] + std::string(".replace"));
    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error: Unable to open files\n";
        return 1;
    }
    std::string line;
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    while (std::getline(inputFile, line)) {
        customReplace(line, s1, s2);
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();
    std::cout << "File copied with replacements\n";
    return 0;
}