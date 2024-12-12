#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;


//這題的核心，別想太多，這題要用到有向圖跟拓撲排序法，基本上我卡在．如果同時多個indegree為0
class Solution {
public:
    int answer = 0; 
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
    int sumMiddleNumber(std::vector<int> line,std::unordered_map<int,std::unordered_set<int>> after,std::unordered_map<int,std::unordered_set<int>> before){
        int middleIndex = (line.size()-1)/2;
        int left = 0;
        int right = line.size()-1;
        int prevNum = 0;
        int nextNum = 0;
        while(left<=right){
            if(left&&after.contains(line[left])&&after[line[left]].contains(prevNum)){
                
                return 0;
            }
            prevNum =  line[left++];
        }
        while(right>=0){
            if(right!=line.size()-1&&before.contains(line[right])&&before[line[right]].contains(nextNum)){
                return 0;
            }
            nextNum =  line[right--];
        } 
        answer+=line[middleIndex];
        return line[middleIndex];
    }
    int sumMiddleNumberP2(std::vector<int> line , std::unordered_map<int,std::vector<int>> graph){
        std::unordered_set<int> nowNums = std::unordered_set(line.begin(),line.end());
        std::unordered_map<int,int> inDegrees;
        std::vector<int> sortedVec; 
        std::unordered_set<int> processNum;
        std::vector<int> zeroIndNums;
        bool pass = true;
        for(auto num : line){
            for(auto number : graph[num]){
                if(nowNums.count(number)) inDegrees[number]++;
                if(processNum.count(number)) pass = false;
            }
            processNum.emplace(num);
        }
        if(pass) return 0;
        else{
            for (int num : line) {
                if (inDegrees[num] == 0) {
                    zeroIndNums.push_back(num);
                }
            }

            for (int zeroIndNum : zeroIndNums) {
                topoSort(zeroIndNum,graph, sortedVec, inDegrees, nowNums);
            }

            // 累加排序後的中間頁面值
            answer += sortedVec[sortedVec.size() / 2];
        }
        return answer; 
    }

    void topoSort(int nowNum,std::unordered_map<int,std::vector<int>> graph,std::vector<int>& sortedVec,std::unordered_map<int,int>& inDegrees,std::unordered_set<int> nowNums){
        sortedVec.emplace_back(nowNum);
        for(auto node:graph[nowNum]){
            if(nowNums.contains(node)){
                if(--inDegrees[node] == 0) this->topoSort(node,graph,sortedVec,inDegrees,nowNums);
            }
        }
        return ;
    }
    int sumMiddleNumberP3(std::vector<int> line , std::unordered_map<int,std::vector<int>> graph){
        std::unordered_set<int> nowNums = std::unordered_set(line.begin(),line.end());
        std::unordered_map<int,int> inDegrees;
        std::vector<int> sortedVec; 
        std::unordered_set<int> processNum;
        std::vector<int> zeroIndNums;
        bool pass = true;
        for(auto num : line){
            for(auto number : graph[num]){
                if(nowNums.count(number)) inDegrees[number]++;
                if(processNum.count(number)) pass = false;
            }
            processNum.emplace(num);
        }
        if(pass) return 0;
        else{
            for (int num : line) {
                if (inDegrees[num] == 0) {
                    zeroIndNums.push_back(num);
                }
            }

            for (int zeroIndNum : zeroIndNums) {
                topoSort(zeroIndNum,graph, sortedVec, inDegrees, nowNums);
            }

            // 累加排序後的中間頁面值
            answer += sortedVec[sortedVec.size() / 2];
        }
        return answer; 
    }

    void topoSort(int nowNum,std::unordered_map<int,std::vector<int>> graph,std::vector<int>& sortedVec,std::unordered_map<int,int>& inDegrees,std::unordered_set<int> nowNums){
        sortedVec.emplace_back(nowNum);
        for(auto node:graph[nowNum]){
            if(nowNums.contains(node)){
                if(--inDegrees[node] == 0) this->topoSort(node,graph,sortedVec,inDegrees,nowNums);
            }
        }
        return ;
    }
};

int main(){
    std::ifstream inputFile("rule.txt");
    std::string line ;
    Solution solution  = Solution();
    std::vector<std::vector<int>> allIntLine = std::vector<std::vector<int>>(); 
    while (std::getline(inputFile, line)) { 
        allIntLine.emplace_back(solution.split(line,'|'));
    }  
    std::unordered_map<int,std::unordered_set<int>> after;
    std::unordered_map<int,std::unordered_set<int>> before;
    int index = 0;
    for(auto intLine : allIntLine){
        int beforeNumber = intLine[0];
        int afterNumber = intLine[1];
        if(!after.contains(beforeNumber)) after[beforeNumber] = std::unordered_set<int>();
        after[beforeNumber].emplace(afterNumber);
        if(!before.contains(afterNumber)) before[afterNumber] = std::unordered_set<int>();
        before[afterNumber].emplace(beforeNumber);
    }
    
    std::unordered_map<int,std::vector<int>> graph;
    for(auto intLine : allIntLine){
        int beforeNumber = intLine[0];
        int afterNumber = intLine[1];
        if(!graph.contains(beforeNumber)) graph[beforeNumber] =  std::vector<int>();
        graph[beforeNumber].emplace_back(afterNumber);
    }

    std::ifstream inputFile2("input.txt");
    while (std::getline(inputFile2, line)) { 
       solution.sumMiddleNumberP2(solution.split(line,','),graph);
    }   
    inputFile.close();   
    cout<<solution.answer<<endl; 
    return 0;
    
};