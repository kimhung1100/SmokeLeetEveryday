#include <bits/stdc++.h>
using namespace std;

// M.C = O(n) T.C = O(nlogn)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> res;
        unordered_map <int, int> m;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        for(auto i : m){
            pq.push(make_pair(i.second, i.first)); // O(nlogn)
            if(pq.size() > k)
                pq.pop();
        }
        while(pq.size() > 0){
            res.push_back(pq.top().second);
            pq.pop(); // O(nlogn)
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = s.topKFrequent(nums, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}