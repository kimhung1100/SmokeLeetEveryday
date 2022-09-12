#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int maxCount = 0;

        int begin = 0;
        int end = 0;

        int ans = 0;
        while(end < s.size()){
            count[s[end] - 'A']++;
            maxCount = max(maxCount, count[s[end] - 'A']);
            if(end - begin + 1 - maxCount > k){
                count[s[begin] - 'A']--;
                begin++;
            }
            ans = max(ans, end - begin + 1);
            end++;
        }
        return ans;
    }
};