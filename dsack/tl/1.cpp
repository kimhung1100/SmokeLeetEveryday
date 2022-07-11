#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Node { public: string value; Node* left = NULL; Node* right = NULL; };
class ExpTree {
private:
      Node* root;
public:
    bool isSymmetric(){
        
        Node* left = root->left;
        Node* right = root -> right;
        if(left->value != right -> value) return 0;
        Node* left1 = left ->left;
        Node* left2 = left ->right;
        if(left1 -> value != left2 -> value) return 0;
        Node* right1 = right ->left;
        Node* right2 = right ->right;
        if(right1 -> value != right2 -> value) return 0;
        return 1;
    }
};
int main(){
    
}