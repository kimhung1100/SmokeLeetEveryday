#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        int ans = 0;
        unordered_set<char> m;
        while(end < s.size()){
            if(m.find(s[end]) == m.end()){ // if not found
                ans = max(ans, end - start + 1);
                m.insert(s[end]);
                end++;
            }
            else{
                m.erase(s[start]);
                start++;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    string s1 = "abcabcbb";
    cout << s.lengthOfLongestSubstring(s1) << endl;
    return 0;
}
