#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int i = 0; i < nums.size(); i++)
            st.insert(nums[i]);
        int max_len = 0;
        int len = 1;
        for(int x : st){
            if(st.find(x-1) != st.end()){
                len++;
                max_len = max(len,max_len);
                if(st.find(x+1) == st.end()) len = 1;
            }
        }
        return max_len;
    }
};