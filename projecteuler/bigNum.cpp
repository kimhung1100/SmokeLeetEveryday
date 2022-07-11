#include <iostream>
#include <string>
#include <vector>
using namespace std;
string addBN(string a, string b){
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int reminder = 0;
    string ans;
    while(i >= 0 || j >= 0){
        int sum = reminder;
        sum = i >= 0 ? sum + a[i] - '0' : sum;
        sum = j >= 0 ? sum + b[j] - '0' : sum;
        if(sum >= 10){
            reminder = 1;
            sum = sum % 10;
        }
        else
            reminder = 0;
        char tempChar = sum + '0';
        string temp;
        temp.push_back(tempChar);
        ans = temp + ans;
        i --;
        j --;
    }
    if(reminder == 1) ans = "1" + ans;
    return ans;
}
// return a - b (a > b)
string subBN(string a, string b){
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int reminder = 0;
    string ans;
    while(i >= 0 || j >= 0){
        int sum = reminder;
        sum = i >= 0 ? sum + a[i] - '0' : sum;
        sum = j >= 0 ? sum - (b[j] - '0') : sum;
        if(sum < 0){
            reminder = -1;
            sum = (10+a[i] -'0'- (b[j] - '0')) % 10;
        }
        else
            reminder = 0;
        char tempChar = sum + '0';
        string temp;
        temp.push_back(tempChar);
        ans = temp + ans;
        i --;
        j --;
    }
    if(reminder == 1) ans = "1" + ans;
    for(int i = 0; i < ans.size(); i ++){
        if(ans[i] != '0'){
            ans = ans.substr(i);
            break;
        }
    }
    return ans;
}
// multiply two numbers
string mulBN(string a, string b){
    if(a == "0" || b == "0") return "0";
    if(a[0] == '-' && b[0] == '-') return mulBN(a.substr(1), b.substr(1));
    else if(a[0] == '-' ) return "-" + mulBN(a.substr(1), b.substr(0));
    else if(b[0] == '-') return "-" + mulBN(a.substr(0), b.substr(1));
    if(b.size() > a.size()) return mulBN(b, a);
    vector<int> result(a.size() + b.size(), 0);

    int index = 0;
    int carry = 0;
    for(int i = a.size() - 1; i >= 0; i --){
        
        int numA = (int)a[i] - '0';

        for(int j = b.size() - 1; j >= 0; j --){
            int numB = (int)b[j] - '0';
            int sum = numA * numB + result[index + b.size() - 1 - j] + carry;
            carry = sum / 10;
            result[index + b.size() - 1 - j] = sum % 10;
        }
        if(carry > 0)  {result[index + b.size()] = carry; carry = 0;}
        index++;
    }
    string ans;
    for(int i = 0; i < result.size(); i ++){
        char tempChar = result[i] + '0';
        string temp;
        temp.push_back(tempChar);
        ans = temp + ans;
    }
    for(int i = 0; i < ans.size(); i ++){
        if(ans[i] != '0'){
            ans = ans.substr(i);
            break;
        }
    }
    return ans;
}
// divide two numbers
// first reference is string, second reference is int
// return a string of quotient and remainder
string divBN(string a, int b){
    string ans;
    int index = 0;
    int temp = a[0] - '0';
    while(temp < b){
        temp = temp * 10 + a[index + 1] - '0';
        index ++;
    }
    while(a.size() > index){
        ans += (temp / b) + '0';
        temp = temp % b * 10 + a[++index] - '0';
    }
    if(ans.length() == 0) ans = "0";
    return ans;
}
