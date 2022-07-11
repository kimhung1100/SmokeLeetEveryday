#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
};
BTNode* help(BTNode* root, int a, int b){
    if(root->val == a || root->val == b) return root;
    BTNode* left = help(root->left,a,b);
    BTNode* right = help(root->right,a,b);
    if(left && right) 
        return root;
    return(left!= nullptr) ? left: right;
    
}
int lowestAncestor(BTNode* root, int a, int b) {
    if(root == nullptr) return NULL;
    BTNode* ans = help(root,a,b);
    return ans->val;
}
int main(){
    int arr[] = {-1,0,0,2,2,3,3};
    //BTNode* root = BTNode::createTree(arr, arr + sizeof(arr) / sizeof(int), NULL);
    cout << lowestAncestor(root, 4, 5);
}