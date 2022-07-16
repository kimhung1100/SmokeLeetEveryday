#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    // T.C = O(nlogk)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>>m;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(strs[i]);
            
        }
        for(auto it = m.begin(); it != m.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> ans = s.groupAnagrams(strs);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}