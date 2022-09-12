#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = 0;
        int ans = 0;
        for(int i = 0; i < height.size(); i++){
            if(height[i] > height[left]){
                left = i;
            }
        }
    }
};