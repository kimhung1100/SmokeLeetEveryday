#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lRow = 0, rRow = matrix.size()-1;
        int lCol = 0, rCol = matrix[0].size()-1;
        while(lRow < rRow){
            int midRow = lRow + (rRow- lRow)/2;
            if(matrix[midRow][0] == target) return true;
            else if(matrix[midRow][0] < target && target < matrix[midRow+1][0]) {
                lRow = midRow;
                break;
            }
            else if(matrix[midRow][0] < target) lRow = midRow + 1;
            else rRow = midRow-1;
        }
        int row = lRow;
        while(lCol <= rCol){
            int midCol = lCol + (rCol- lCol)/2;
            if(matrix[row][midCol] == target) return true;
            else if(matrix[row][midCol] < target) lCol = midCol+1;
            else rCol = midCol-1;
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<vector<int>> matrix = {{1}, {3}};
    int target = 3;
    bool ans = s.searchMatrix(matrix, target);
    cout << ans << endl;
    return 0;
}