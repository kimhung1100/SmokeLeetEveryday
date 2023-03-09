<<<<<<< HEAD
#include <iostream>

using namespace std;
class Solution {
public:
    bool withoutRepeating(string s){
        int count[256];
        fill_n(count, 256, 0);
        for(int i = 0; i < s.size(); i++){
            count[s[i]]++;
            if(count[s[i]] > 1) return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int start = 0;
        int end = 0;
        for(;end < s.size(); end++){
            if(withoutRepeating(s.substr(start, end - start + 1))){
                max = max > (end - start + 1) ? max : (end - start + 1);
            }
            else{
                while(!withoutRepeating(s.substr(start, end - start + 1))){
                    start++;
                }
            }
        }
        return max;
    }
};

int main(){
    Solution s;
    string str;
    cin >> str;
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
=======
#include <iostream>

using namespace std;
class Solution {
public:
    bool withoutRepeating(string s){
        int count[256];
        fill_n(count, 256, 0);
        for(int i = 0; i < s.size(); i++){
            count[s[i]]++;
            if(count[s[i]] > 1) return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int start = 0;
        int end = 0;
        for(;end < s.size(); end++){
            if(withoutRepeating(s.substr(start, end - start + 1))){
                max = max > (end - start + 1) ? max : (end - start + 1);
            }
            else{
                while(!withoutRepeating(s.substr(start, end - start + 1))){
                    start++;
                }
            }
        }
        return max;
    }
};

int main(){
    Solution s;
    string str;
    cin >> str;
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
>>>>>>> 30ab1405424e301735fbce3f9a5fb163c529c7b9
}