#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    int answer = 0;
    int count = 0;
    int count2 = 0;
    int findMulti2(std::string& line){

        for (size_t oIndex = 0; oIndex < line.size(); oIndex++) {
            if (oIndex + 4 < line.size() && line[oIndex] == 'm' && line[oIndex + 1] == 'u' && line[oIndex + 2] == 'l' && line[oIndex + 3] == '(') {

                auto index=oIndex+4;
                size_t limit = line.size()>=index+8?index+8:line.size();
                std::string xNum = "";
                std::string rNum = "";
                size_t pointIndex = 0;
                size_t rightIndex = 0;
                //優化不是 數字以及,以及)就跳出去
                while(index<limit){
                    if(line[index]==','){
                        pointIndex = index;
                    }
                    else if(line[index]==')') {
                        rightIndex = index;
                        break;
                    }
                    else{
                        if(!pointIndex) xNum+=line[index];
                        else rNum +=line[index];
                    }
                    index++;
                }
                if(pointIndex && pointIndex<rightIndex && all_of(xNum.begin(), xNum.end(), ::isdigit) && all_of(rNum.begin(), rNum.end(), ::isdigit)){
                    this->answer+=(std::stoi(xNum)*std::stoi(rNum));
                    cout<<this->count++<<endl;
                    // cout<<index<<endl;
                    // cout<<answer<<endl;
                    // cout<<"X-"+xNum<<endl;
                    // cout<<"R-"+rNum<<endl;
                }   
            }
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
            cout<<this->count2++<<endl;         
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
        // solution.findMulti(line);
        solution.findMulti2(line);
    }  
    // cout<<answer<<endl;
    inputFile.close();   
    return 0;
    
};