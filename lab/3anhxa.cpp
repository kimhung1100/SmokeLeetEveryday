// Include additional libraries and write helper functions here
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char anhXa[26];
char anhXa2[26];
/*
bool checkIsomorphicString(string& s, string& t) {
    // To Do
    anhXa[0] = 'a';
    for(int i = 1; i < 26; i++){
        anhXa[i] = anhXa[i - 1] + 1;
    }
    fill_n(anhXa2,24,'0');
    for(int i = 0; i < (int)s.size(); i++){
        if(anhXa2[s[i] - 'a'] == '0') { // chua anh xa
            anhXa2[s[i] - 'a'] = t[i];
            anhXa2[t[i] - 'a'] = s[i];
        }else {
            if(anhXa2[s[i] - 'a'] != t[i]){
                fill_n(anhXa2,24,'0');
                return 0;
            }
                
            else continue;
        }
    }
    fill_n(anhXa2,24,'0');
    return 1;
}*/
bool checkIsomorphicString(string& s, string& t) {
    // To Do
    anhXa[0] = 'a';
    for(int i = 1; i < 26; i++){
        anhXa[i] = anhXa[i - 1] + 1;
    }
    fill_n(anhXa2,24,'0');
    for(int i = 0; i < (int)s.size(); i++){
        if(anhXa2[s[i] - 'a'] == '0') { // chua anh xa
            anhXa2[s[i] - 'a'] = t[i];
        }else {
            if(anhXa2[s[i] - 'a'] != t[i]){
                fill_n(anhXa2,24,'0');
                return 0;
            }
                
            else continue;
        }
    }
    fill_n(anhXa2,24,'0');
    for(int i = 0; i < (int)s.size(); i++){
        if(anhXa2[t[i] - 'a'] == '0') { // chua anh xa
            anhXa2[t[i] - 'a'] = s[i];
        }else {
            if(anhXa2[t[i] - 'a'] != s[i]){
                fill_n(anhXa2,24,'0');
                return 0;
            }
                
            else continue;
        }
    }
    return 1;
}
int main(){
    string s, t;
    cin >> s >> t;
    cout << (checkIsomorphicString(s, t) ? "true" : "false");
}