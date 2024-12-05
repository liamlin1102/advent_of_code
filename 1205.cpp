#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    std::vector<int> split(const std::string& str, char delimiter) {
        std::vector<int> tokens;
        size_t start = 0;
        size_t end = str.find(delimiter);

        while (end != std::string::npos) {
            tokens.push_back(std::stoi(str.substr(start, end - start)));
            start = end + 1; 
            end = str.find(delimiter, start);
        }

        tokens.push_back(std::stoi(str.substr(start))); 

        return tokens;
    }
};

int main(){
    std::ifstream inputFile("rule.txt");
    std::string line ;
    auto solution  = Solution();
    while (std::getline(inputFile, line)) { 
       auto intLine = solution.split(line,'|');
    }  
    std::unordered_map<int,int> after;
    std::unordered_map<int,int> before;
    std::ifstream inputFile("input.txt");
    auto solution  = Solution();
    while (std::getline(inputFile, line)) { 
       auto input = solution.split(line,',');
    }   
    inputFile.close();    
    return 0;
    
};