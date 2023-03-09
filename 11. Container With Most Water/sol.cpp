#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
// T.c = O(n) M.c = O(1)
    int maxArea(vector<int>& height) {
        int ans = 0;
        int area = 0;
        int it1 = 0, it2 = 1;
        it2 = height.size() - 1;
        while(it1 < it2){
            area = min(height[it1], height[it2]) * (it2 - it1);
            ans = max(ans, area);
            if(height[it1] < height[it2]){
                it1++;
            }else{
                it2--;
            }
        }
        return ans;
    }
};