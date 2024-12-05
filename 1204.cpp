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

        int SearchWordP2(std::vector<std::vector<char>>& wordMatrix){
            if(wordMatrix.size()==0 || wordMatrix[0].size()==0) return 0;
            this->rowSize = wordMatrix.size();
            this->columnSize = wordMatrix[0].size();
            int answer = 0;
            
            for(int row = 0; row<rowSize; row++){
                for(int column = 0; column<columnSize; column++){
                    if(wordMatrix[row][column]=='A'){
                        answer+=this->checkWordP2(row,column,wordMatrix);
                    }
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
                {-1, -1},//往左下
                {1, -1},//往左上
                {-1, 1}//往右下
            };
            std::string target = "XMAS";
            int targetSize = target.size();
            for(auto [rowMove,columnMove] : directions){
                int limitRow = row+rowMove*(targetSize-1);
                int limitColumn = column+columnMove*(targetSize-1);             
                if(limitRow<0 || limitColumn<0 || limitRow>=this->rowSize || limitColumn>=this->columnSize){
                    continue;
                }   
                total+=this->validateWord(row,rowMove,column,columnMove,wordMatrix,target,targetSize);
            }
            return total;
        }

        int checkWordP2(int row,int column,std::vector<std::vector<char>>& wordMatrix){
            int total = 0;
            std::vector<pair<int, int>> directions = {
                {1, 1},//往右上
                {-1, -1},//往左下
            };
            std::vector<pair<int, int>> directions2 = {
                {1, -1},//往左上
                {-1, 1}//往右下
            };
            std::unordered_map<char, int> target = {
                {'M', 1},
                {'S', 1}
            };
            for(auto [rowMove,columnMove] : directions){
                int limitRow = row+rowMove;
                int limitColumn = column+columnMove;             
                if(limitRow<0 || limitColumn<0 || limitRow>=this->rowSize || limitColumn>=this->columnSize){
                    return 0;
                }   
                if(!this->validateWordP2(row,rowMove,column,columnMove,wordMatrix,target))
                    return 0;
            }
            target = {
                {'M', 1},
                {'S', 1}
            };
            for(auto [rowMove,columnMove] : directions2){
                int limitRow = row+rowMove;
                int limitColumn = column+columnMove;             
                if(limitRow<0 || limitColumn<0 || limitRow>=this->rowSize || limitColumn>=this->columnSize){
                    return 0;
                }   
                if(!this->validateWordP2(row,rowMove,column,columnMove,wordMatrix,target))
                    return 0;
            }
            cout<<wordMatrix[row+1][column-1]<<wordMatrix[row-1][column+1]<<wordMatrix[row][column]<<wordMatrix[row+1][column+1]<<wordMatrix[row-1][column-1]<<endl;
            return 1;
        }

        int validateWord(int& row,int& rowMove,int& column,int& columnMove,std::vector<std::vector<char>>& wordMatrix,std::string& target,int& targetSize){
            for(int index = 0; index<targetSize; index++){
                if(wordMatrix[row+rowMove*index][column+columnMove*index]!=target[index])
                    return 0;
            }
            return 1;
        }

        bool validateWordP2(int& row,int& rowMove,int& column,int& columnMove,std::vector<std::vector<char>>& wordMatrix,std::unordered_map<char, int>& target){
            if(target[wordMatrix[row+rowMove][column+columnMove]]){
                target[wordMatrix[row+rowMove][column+columnMove]]--;
                return true;
            }
            return false;
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
    cout<<solution.SearchWordP2(wordMatrix)<<endl;
    return 0;
}