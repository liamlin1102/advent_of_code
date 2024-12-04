#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    int answer = 0;
    int findMulti2(std::string& line){
        size_t index = 0;
        while(index+5 < line.size()) {
            if (line[index] == 'm' && line[index + 1] == 'u' && line[index + 2] == 'l' && line[index + 3] == '(') {
                index+=3;
                std::string xNum = "";
                std::string rNum = "";
                size_t pointIndex = 0;
                size_t rightIndex = 0;
                //優化不是 數字以及,以及)就跳出去
                bool pass = true;
                while(true){
                    if(line[++index]==','){
                        pointIndex = index;
                    }
                    else if(line[index]==')') {
                        rightIndex = index;
                        break;
                    }
                    else if(!isdigit(line[index])){
                        pass = false;
                        break;
                    }
                    else{
                        if(!pointIndex) xNum+=line[index];
                        else rNum +=line[index];
                    }
                    
                }
                if(pointIndex && pointIndex<rightIndex && pass){
                    this->answer+=(std::stoi(xNum)*std::stoi(rNum));
                }   
            }
            else index++;
        }
        return answer;
    }
    int findMultiP2(std::string& line){

        bool doit = true;
        size_t index = 0;
        while(index+5 < line.size()) {
            if(index + 7 < line.size() && line[index]== 'd' && line[index+1]== 'o' && line[index+2]== 'n' && line[index+3]== '\'' && line[index+4]=='t' && line[index+5]=='(' && line[index+6]==')' ){
                doit = false;
                index+=7;
                while(!doit){
                    if(index + 9 > line.size()){
                        return 0;
                    }
                    if(line[index]== 'd' && line[index+1]== 'o' && line[index+2]== '(' && line[index+3]== ')'){
                        doit = true;
                        index+=4;
                    }
                    else index++;
                }
            }
            if (line[index] == 'm' && line[index + 1] == 'u' && line[index + 2] == 'l' && line[index + 3] == '(') {
                index+=3;
                std::string xNum = "";
                std::string rNum = "";
                size_t pointIndex = 0;
                size_t rightIndex = 0;
                //優化不是 數字以及,以及)就跳出去
                bool pass = true;
                while(true){
                    if(line[++index]==','){
                        pointIndex = index;
                    }
                    else if(line[index]==')') {
                        rightIndex = index;
                        break;
                    }
                    else if(!isdigit(line[index])){
                        pass = false;
                        break;
                    }
                    else{
                        if(!pointIndex) xNum+=line[index];
                        else rNum +=line[index];
                    }
                    
                }
                if(pointIndex && pointIndex<rightIndex && pass){
                    this->answer+=(std::stoi(xNum)*std::stoi(rNum));
                }   
            }
            else index++;
        }
        return answer;
    }
    int findMulti(const std::string& line) {
        int totalSum = 0;
        

        // 正規表達式：匹配 mul(X,Y)
        std::regex regexPattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
        std::smatch match;

        // 使用 std::sregex_iterator 遍歷所有匹配
        auto begin = std::sregex_iterator(line.begin(), line.end(), regexPattern);
        auto end = std::sregex_iterator();

        for (auto it = begin; it != end; ++it) {
            match = *it;
            int x = std::stoi(match[1].str()); 
            int y = std::stoi(match[2].str()); 
            totalSum += x * y;        
        }

        return totalSum;
    }

};

int main(){
    std::ifstream inputFile("input.txt");
    std::string line ;
    auto solution  = Solution();
    int answer = 0;
    while (std::getline(inputFile, line)) { 
        // answer+=solution.findMulti(line);
        solution.findMultiP2(line);
    }  
    cout<<solution.answer<<endl;
    // cout<<answer<<endl;
    inputFile.close();   
    return 0;
    
};