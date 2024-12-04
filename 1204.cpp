#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;


class Solution{
    public:
        int rowSize;
        int columnSize;
        int SearchWord(std::vector<std::vector<char>>& wordMatrix){
            if(wordMatrix.size()==0 || wordMatrix[0].size()==0) return 0;
            this->rowSize = wordMatrix.size();
            this->columnSize = wordMatrix[0].size();
            int answer = 0;
            
            for(int row = 0; row<rowSize; row++){
                for(int column = 0; column<columnSize; column++){
                    answer+=this->checkWord(row,column,wordMatrix);
                }
            }   
            return answer;

        }
        int checkWord(int& row,int& column,std::vector<std::vector<char>>& wordMatrix){
            int total = 0;
            std::vector<pair<int, int>> directions = {
                {0, 1},//往右
                {0, -1},//往左
                {1, 0},//往上
                {-1, 0},//往下
                {1, 1},//往右上
                {-1, -1},//往左上
                {1, -1},//往右下
                {-1, 1}//往左下
            };
            std::string target = "XMAS";
            int targetSize = target.size();
            for(auto [rowMove,columnMove] : directions){
                int limitRow = row+rowMove*targetSize;
                int limitColumn = column+columnMove*targetSize;                
                if(limitRow<0 || limitColumn<0 || limitRow>=this->rowSize || limitColumn>=this->columnSize)
                    continue;
                total+=this->validateWord(row,rowMove,column,columnMove,wordMatrix,target,targetSize);
            }
            return total;
        }
    int validateWord(int& row,int& rowMove,int& column,int& columnMove,std::vector<std::vector<char>>& wordMatrix,std::string& target,int& targetSize){
        for(int index = 0; index<targetSize; index++){
            if(wordMatrix[row+rowMove*index][column+columnMove*index]!=target[index])
                return 0;
        }
        return 1;
    }
};
int main(){
    std::ifstream inputFile("input.txt");
    std::string line ;
    std::vector<std::vector<char>> wordMatrix;
    while (std::getline(inputFile, line)) { 
        std::vector<char> words;
        for(auto word : line){
            words.emplace_back(word);
        }
        wordMatrix.emplace_back(words);
    }
    Solution solution = Solution();
    cout<<solution.SearchWord(wordMatrix)<<endl;
    return 0;
}