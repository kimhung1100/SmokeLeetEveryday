class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> result;
        generate(n, 0, 0, "", result);
        return result;
    }
    void generate(int n, int open, int close, string str,vector<string>& result){
        if(open == n && close == n){ // the end
            result.push_back(str);
            return;
        }
        if(open < n){
            generate(n, open + 1, close, str + "(", result);
        }
        if(close < open){
            generate(n, open, close + 1, str + ")", result);
        }   
    }
};
int main(){
    Solution s;
    vector<string> result = s.generateParenthesis(3);
    for(auto i : result){
        cout << i << endl;
    }
    return 0;
}