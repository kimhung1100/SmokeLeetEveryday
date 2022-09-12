#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars; // position, speed
        for(int i = 0; i < position.size(); i++){
            cars.push_back(make_pair(position[i], speed[i]));
        }
        sort(cars.begin(), cars.end());
        int ans = 0;
        bool createCarFleet = false;
        stack<pair<int, int>> st; // position, speed
        st.push(make_pair(cars[0].first, cars[0].second));
        for(int i = 1; i < position.size(); i++){
            if(cars[i].second < st.top().second){ // the sooner car is faster than the later car, can become a fleet
                int time = floor((cars[i].first - st.top().first) / (st.top().second - cars[i].second));
                if(cars[i].first + time * cars[i].second <= target){
                    createCarFleet = true;
                    st.pop();
                    st.push(make_pair(cars[i].first + cars[i].second*time, cars[i].second));
                }else{
                    st.push(make_pair(cars[i].first, cars[i].second));
                }
            }else{
                if(createCarFleet){
                    ans++;
                    createCarFleet = false;
                    st.pop();
                    st.push(make_pair(cars[i].first, cars[i].second));
                    continue;
                }
                st.push(make_pair(cars[i].first, cars[i].second));
            }
        }
        return ans+st.size();
    }
};
int main(){
    Solution s;
    int target = 10;
    vector<int> position = {0, 4, 2};
    vector<int> speed = {2, 1, 3};
    int ans = s.carFleet(target, position, speed);
    cout << ans << endl;
    return 0;
}