#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;


//這題的核心，別想太多，這題要用到有向圖跟拓撲排序法，基本上我卡在．如果同時多個indegree為0
class Solution {
public:
    std::vector<std::vector<std::pair<char,int>>> area = std::vector<std::vector<std::pair<char,int>>>(); 
    int yLimit = 0;
    int xLimit = 0 ;
    std::vector<std::pair<int,int>> directions = std::vector<std::pair<int,int>>{
        {0,-1},
        {1,0},
        {0,1},
        {-1,0}
    };
    bool in = true;

    int backtracking(int& guardX,int& guardY,std::pair<int,int> nowDirection){
        int newX = guardX+nowDirection.first;
        int newY = guardY+nowDirection.second;
        if(newX<0||newY<0||newX>=xLimit || newY>=yLimit||area[newY][newX].first=='#'){
            if(newX<0||newY<0||newX>=xLimit || newY>=yLimit) in = false;
            return 0;
        }
        guardX = newX;
        guardY = newY;
        int newArea =  area[guardY][guardX].second;
        area[guardY][guardX].second = 0;
        return newArea+backtracking(guardX,guardY,nowDirection);
    }
    int movingOut(int& guardX,int& guardY){
        int answer = 1;
        int cycle = 0;
        area[guardY][guardX].second = 0;
        while(in){
            // cout<<guardX<<guardY<<endl;
            // cout<<cycle%4<<endl;
            answer+=backtracking(guardX,guardY,directions[cycle++%4]);
        }
        return answer;
    }
};

int main(){
    std::ifstream inputFile("input.txt");
    std::string line ;
    Solution solution  = Solution();
    int anwer= 0;
    int guardX = 0;
    int guardY = 0;
    int nowY = 0;
    while (std::getline(inputFile, line)) { 
        std::vector<std::pair<char,int>> temp = std::vector<std::pair<char,int>>();
        for(int nowX = 0 ; nowX<line.size();nowX++){
            temp.emplace_back(line[nowX],1);
            if(line[nowX]=='^'){
                guardX = nowX;
                guardY = nowY;
            }
        }
        solution.area.emplace_back(temp);
        nowY++;
    }  
    solution.xLimit =  solution.area[0].size();
    solution.yLimit = solution.area.size();
    cout<<solution.movingOut(guardX,guardY)<<endl;
    return 0;
};