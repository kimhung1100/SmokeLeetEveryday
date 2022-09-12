#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));
        for(int i = 0; i < board.size(); i++){
            for(int j =0; j < board.size(); j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    int box_index = (i / 3) * 3 + j / 3;
                    if(row[i][num] || col[j][num] || box[box_index][num])
                        return false;
                    row[i][num] = true;
                    col[j][num] = true;
                    box[box_index][num] = true;
                }
            
            }
        }
    }
    
};