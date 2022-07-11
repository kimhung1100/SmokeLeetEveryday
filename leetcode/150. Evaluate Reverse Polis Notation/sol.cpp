#include<bits/stdc++.h>
using namespace std;
class Solution {
public: // T.C. O(n)
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(int i = 0; i < tokens.size(); i++){
            int a, b;
            switch (tokens[i][0]){
                case '+':
                    a = st.top();
                    st.pop();
                    b = st.top();
                    st.pop();
                    st.push(a+b);
                    break;
                case '-':
                    if(tokens[i].size()!= 1){
                        st.push(stoi(tokens[i]));
                        break;
                    }
                    a = st.top();
                    st.pop();
                    b = st.top();
                    st.pop();
                    st.push(b-a);
                    break;
                case '*':
                    a = st.top();
                    st.pop();
                    b = st.top();
                    st.pop();
                    st.push(a*b);
                    break;
                case '/':
                    a = st.top();
                    st.pop();
                    b = st.top();
                    st.pop();
                    st.push(b/a);
                    break;
                default:
                    st.push(stoi(tokens[i]));
                    break;
            }
            
        }
        return st.top();
    }
};
int main(){
    Solution s;
    vector<string> v = {"-10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << s.evalRPN(v) << endl;
    return 0;
}