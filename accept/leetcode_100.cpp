/* Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value. */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p!=NULL&&q!=NULL&&p->val == q->val){
            bool left = isSameTree(p->left,q->left);
            bool right = isSameTree(p->right,q->right);
            return left&&right;
        }else if(p==NULL&&q==NULL){
            return true;
        }else{
            return false;
        }
        
       
    }
};

int main()
{
    Solution s;
 

    return 0;
}