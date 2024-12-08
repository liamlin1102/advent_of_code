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
    int sumMiddleNumber(std::vector<int> line,std::unordered_map<int,std::vector<int>> after,std::unordered_map<int,std::vector<int>> before){

    }
};

int main(){
    std::ifstream inputFile("rule.txt");
    std::string line ;
    auto solution  = Solution();
    std::vector<int> intLine ; 
    while (std::getline(inputFile, line)) { 
        intLine = solution.split(line,'|');
    }  
    std::unordered_map<int,std::vector<int>> after;
    std::unordered_map<int,std::vector<int>> before;
    int index = 0;
    while(index < intLine.size()){
        int beforeNumber = intLine[index++];
        int afterNumber = intLine[index++];
        if(!after.contains(beforeNumber)) after[beforeNumber] = std::vector<int>();
        after[beforeNumber].emplace_back(afterNumber);
        if(!before.contains(afterNumber)) before[afterNumber] = std::vector<int>();
        before[afterNumber].emplace_back(beforeNumber);
    }
    std::ifstream inputFile("input.txt");
    auto solution  = Solution();
    while (std::getline(inputFile, line)) { 
       auto input = solution.split(line,',');
    }   
    inputFile.close();    
    return 0;
    
};