#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "set"
#include <regex>

std::string transform(std::string& input){
    std::string lower_str = input;
    std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
    return lower_str;
}

std::string removePunctuation(std::string& input){
    std::string result = "";
    for(char c : input){
        if(isalnum(c) || c == ' '){
            result += c;
        }
    }
    return result;
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    std::ofstream outputUrl("urls.txt");

    std::map<std::string, int> words; //Fiksuoja kiek kartu pasikartoja zodis
    std::map<std::string, std::set<int>> wordLines; //Fiksuoja koks key[zodis] turi pasikartojima kurioj linijoj

    std::vector<std::string> urlVector;

    std::regex ulrRegex(R"((http[s]?://[^\s]+|www\.[^\s]+|[^\s]+\.[a-z]{2,}))");

    std::string line = "";

    int lineNumber = 0;

    if(!inputFile.is_open()){
        std::cerr << "Nepavyko atidaryti failo" << std::endl;
    }

    while(std::getline(inputFile, line)){
        ++lineNumber;
        std::istringstream lineStream(line);
        std::string word;

        while(lineStream >> word){
            std::string lowerWord = transform(word);
            std::string cleanWord = removePunctuation(lowerWord);
            if(std::regex_match(cleanWord, ulrRegex)){
                urlVector.push_back(cleanWord);
            } else {
                words[cleanWord]++;
                wordLines[cleanWord].insert(lineNumber);
            }
        }
    }

    for (const auto &pair : words) {
        if (pair.second > 1) {
            outputFile << pair.first << ": " << pair.second << std::endl;
            outputFile << "Lines: ";
            for (int ln : wordLines[pair.first]) {
                outputFile << ln << " ";
            }
            outputFile << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();
    outputUrl.close();

    return 0;
}

