#include<iostream>

using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        uint32_t a = n;
        while(a != 0){
            if(a%2)
                ans++;
            a/=2;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.hammingWeight(11)<<endl;
    return 0;
}
