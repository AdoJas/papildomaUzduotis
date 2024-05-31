#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "unordered_set"
#include <regex>

std::string transform(std::string& input){
    std::string lower_str = input;
    std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
    return lower_str;
}


int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    std::ofstream outputUrl("urls.txt");

    std::map<std::string, int> words;
    std::map<std::string, std::unordered_set<int>> wordLines;
    std::vector<std::string> urlVector;
    std::regex ulrRegex(R"((http[s]?://[^\s]+|www\.[^\s]+|[^\s]+\.[a-z]{2,}))");
    std::string line = "";
    int lineNumber = 0;
    if(!inputFile.is_open()){
        std::cerr << "Nepavyko atidaryti failo" << std::endl;
    }

    while(std::getline(inputFile, line)){
        ++lineNumber;
        getline(inputFile, line);

    }


    return 0;
}

