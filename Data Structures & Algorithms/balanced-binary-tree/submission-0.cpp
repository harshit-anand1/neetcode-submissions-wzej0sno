/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int height(TreeNode* node, bool& flag){
        if(!node) return 0 ;

        int lh  = height(node->left,flag);
        int rh = height(node->right, flag);

        int diff = abs(lh-rh);
        if(diff>1) flag = false;

        return 1+max(lh,rh);


    }
    bool isBalanced(TreeNode* root) {
       bool flag=true;
       height(root,flag); 
       return flag;
    }
};
