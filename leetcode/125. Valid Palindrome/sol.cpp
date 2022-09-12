#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        for (size_t i = 0; i < s.size(); i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
                s[i] = s[i] + 32;
            else if(s[i]>='a'&&s[i]<='z')
                s[i] = s[i];
            else if(s[i]>='0'&&s[i]<='9')
                s[i] = s[i];
            else{
                s.erase(i,1);
                i--;
            }
        }
        
        int i = 0, j = s.size() - 1;
        while(true){
            if(i > j) break;
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
};
int main(){
    string s = "race a car";
    Solution sl;
    cout << sl.isPalindrome(s);
}