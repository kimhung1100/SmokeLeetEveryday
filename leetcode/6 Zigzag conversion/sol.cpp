#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> v(numRows);
        for(int i = 0; i < s.size(); i ++){
            int row = (i % (2*numRows - 2));
            if(row < numRows) v[row].push_back(s[i]);
            else v[2*numRows - 2 - row].push_back(s[i]);
        }
        string ans;
        for(int i = 0; i < numRows; i++){
            ans += v[i];
        }
        return ans;
    }
};
int main(){
    Solution s;
    string str;
    cin >> str;
    cout << s.convert(str, 4) << endl;
    return 0;
}