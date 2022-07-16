<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletions(string s) {
        if(s.size() == 1) return 0;
        int count[27];
        fill_n(count, 27, 0);
        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
        }
        sort(count, count + 27);
        int ans = 0;
        vector<int> v;
        for(int i = 0; i < 27; i++){
            if(count[i] != 0){
                v.push_back(count[i]);
            }
        }
        int count2[100];
        fill_n(count2, 100, 0);
        for(int i = 0; i < v.size(); i++){
            if(count2[v[i]] == 0) count2[v[i]] = 1;
            else{
                // same
                int j = v[i];
                while(count2[j] != 0 && j != 0){
                    j--;
                }
                count2[j]++;
                ans += v[i] - j;
            }
        }
        return ans;
    }
};
int main(){
    string sz = "abcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwz";
    Solution s;
    cout << s.minDeletions(sz) << endl;
    return 0;
=======
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletions(string s) {
        if(s.size() == 1) return 0;
        int count[27];
        fill_n(count, 27, 0);
        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
        }
        sort(count, count + 27);
        int ans = 0;
        vector<int> v;
        for(int i = 0; i < 27; i++){
            if(count[i] != 0){
                v.push_back(count[i]);
            }
        }
        int count2[100];
        fill_n(count2, 100, 0);
        for(int i = 0; i < v.size(); i++){
            if(count2[v[i]] == 0) count2[v[i]] = 1;
            else{
                // same
                int j = v[i];
                while(count2[j] != 0 && j != 0){
                    j--;
                }
                count2[j]++;
                ans += v[i] - j;
            }
        }
        return ans;
    }
};
int main(){
    string sz = "abcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwz";
    Solution s;
    cout << s.minDeletions(sz) << endl;
    return 0;
>>>>>>> 30ab1405424e301735fbce3f9a5fb163c529c7b9
}