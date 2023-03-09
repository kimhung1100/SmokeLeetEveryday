#include <bits/stdc++.h>
using namespace std;
//* Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
private:
    vector <int> array;
    int ans = 0;
    int cntOdd = 0; 
    void reachNode(TreeNode* node){
        array[node->val] ++;
        if(array[node->val]%2) cntOdd++;
        else cntOdd--;
    }
    void leaveNode(TreeNode* node){
        array[node->val] --;
        if(array[node->val]%2) cntOdd--;
        else cntOdd++;
    }
    void dfsHelper(TreeNode* node){
        if(node == nullptr) return;
        if(node->left == nullptr && node->right == nullptr){
            //leaf Node
            reachNode(node);
            if(cntOdd == 1) ans ++;
            leaveNode(node);
        }else if(node->left && node->right){
            reachNode(node);
            dfsHelper(node->left);
            dfsHelper(node->right);
            leaveNode(node);
        }else if(node->right == nullptr){
            reachNode(node);
            dfsHelper(node->left);
            leaveNode(node);
        }else {
            reachNode(node);
            dfsHelper(node->left);
            leaveNode(node);
        }
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        array = vector<int>(10, 0);
        dfsHelper(root);
        return ans;
    }
};

int main(){
    Solution s;
    //[8,8,null,7,7,null,null,2,4,null,8,null,7,null,1]
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(7);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->left->left->right = new TreeNode(8);
    root->left->left->left->right->left = new TreeNode(7);
    root->left->left->left->right->left->right = new TreeNode(1);
    int ans = s.pseudoPalindromicPaths(root);
    cout << ans << endl;
    return 0;
}