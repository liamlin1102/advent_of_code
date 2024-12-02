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
    int conculate(std::vector<int> line){
        int index = 1;
        bool desc = line[1]>line[0];

        int firstNum = line[0];
        for(index;index<line.size();index++){
            int lastNum = line[index];
            if(desc && lastNum<=firstNum || !desc && lastNum>=firstNum || abs(lastNum-firstNum)>3) return 0;
            firstNum = lastNum;
        }
        return 1;
    }

    //土炮 直接全部跑一次，只要有移除成功版本就好
    //更高階一點的方法應該是，只要遇到狀況，就去跑DP，並且儲存當前的剩餘次數超過1就RETURN回來
    int conculate2(std::vector<int>  line){
        if(this->conculate(line))return 1;
        for(int index=0;index<line.size();index++){
            std::vector<int> deepCopy = line;
            deepCopy.erase(deepCopy.begin()+index);
            if(this->conculate(deepCopy)) return 1;
        }
        return 0;
    }
};

int main(){
    std::ifstream inputFile("input.txt");
    std::string line ;
    auto solution  = Solution();
    int answer = 0;
    while (std::getline(inputFile, line)) { 
       auto intLine = solution.split(line,' ');
       answer+=solution.conculate2(intLine);  
    }  
    inputFile.close();
    std::cout << answer << std::endl;    
    return 0;
    
};