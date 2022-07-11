#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int num = 0, min = 0, max = 0, change = 0;
        for(int i = 0; i < differences.size(); i++){
            num += differences[i];
            if(num < min) min = num;
            if(num > max) max = num;
        }
        max == min ? change = max : change = max - min;
        return upper - lower + 1 - abs(change) <0 ? 0 : upper - lower + 1 - abs(change);
    }
};
int main(){
    Solution s;
    vector<int> differences = {83702,-5216};
    int lower = -82788, upper = 14602;
    cout << s.numberOfArrays(differences, lower, upper) << endl;
    return 0;
}