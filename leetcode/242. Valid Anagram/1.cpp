#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int array[26] = {0};
        for(int i = 0; i < s.size(); i++){
            array[s[i]-'a']++;
            array[t[i]-'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(array[i] != 0) return false;
        }
        return true;
    }
};