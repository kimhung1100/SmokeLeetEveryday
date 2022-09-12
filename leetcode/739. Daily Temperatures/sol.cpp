#include <bits/stdc++.h>
using namespace std;
class Solution {
public: // T.C = O(n) and S.C = O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <pair<int, int>> st;
        vector<int> result(temperatures.size(), 0);
        st.push(make_pair(temperatures[0], 0));
        for(int i = 1; i < temperatures.size(); i++){
            if(temperatures[i] < st.top().first){
                st.push(make_pair(temperatures[i], i));
                continue;
            }
            
            while(!st.empty() && temperatures[i] > st.top().first){ // update
                result[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push(make_pair(temperatures[i], i));
            
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = s.dailyTemperatures(temperatures);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}