<<<<<<< HEAD
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
=======
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
>>>>>>> 30ab1405424e301735fbce3f9a5fb163c529c7b9
