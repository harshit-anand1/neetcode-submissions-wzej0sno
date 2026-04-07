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

    int helper(TreeNode* node, int& maxD){
        if(!node) return 0;

        int left = helper(node->left, maxD);
        int right = helper(node->right, maxD);

        maxD = max(maxD,left + right);

        return 1 + max(left,right);
    

    }
    int diameterOfBinaryTree(TreeNode* root) {
       int maxD = 0;
       helper(root, maxD);
       return maxD; 
    }
};
