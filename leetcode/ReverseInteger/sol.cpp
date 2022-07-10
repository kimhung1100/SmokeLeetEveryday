#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        bool firstNum = false;
        
        while(x != 0){
            if(x% 10 == 0 && firstNum == false){
                x = x / 10;
            }else if(x % 10 != 0 || firstNum == true){
                if(firstNum == false)
                    firstNum = true;
                if(ans > INT_MAX/10 || (ans == INT_MAX/10 && x % 10 > 7)){
                    
                    return 0;
                }
                else if(ans < INT_MIN/10)
                    return INT_MIN;
                ans *= 10;
                ans += x % 10;
                x = x/ 10;
            }
        }
        
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.reverse(1534236469);
}
