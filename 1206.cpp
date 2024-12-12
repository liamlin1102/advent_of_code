#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;


//這題的核心，別想太多，這題要用到有向圖跟拓撲排序法，基本上我卡在．如果同時多個indegree為0
class Solution {
public:
    std::vector<std::vector<std::pair<char,int>>> area ; 
    int yLimit = area.size();
    int xLimit = area[0].size();
    std::vector<std::pair<int,int>> directions = std::vector<std::pair<int,int>>{
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };
    bool in = true;

    int backtracking(int& guardX,int& guardY,std::pair<int,int> nowDirection){
        int newX = guardX+nowDirection.first;
        int newY = guardY+nowDirection.second;
        if(newX==xLimit || newY==yLimit||area[newY][newX].first=='#'){
            return 0;
        }
        area[newY][newX].second = 0;
        return area[newY][newX].second+backtracking(newX,newY,nowDirection);
    }
    int movingOut(int guardX,int guardY){
        int answer = 0;
        while(guardX!=xLimit && guardY==yLimit){
            for(auto direction : directions){
                answer+=backtracking(guardX,guardY,direction);
            }
        }
        return  
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