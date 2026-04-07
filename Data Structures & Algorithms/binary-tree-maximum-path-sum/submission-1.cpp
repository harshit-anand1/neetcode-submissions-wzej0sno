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


    ///refer the question leetcode 543 diameter of a tree for intuition hint

    int helperSum(TreeNode* node, int& maxSum){
        if(!node) return 0;
        int sumL  = max(0,helperSum(node->left, maxSum));
        int sumR  = max(0,helperSum(node->right, maxSum));
        
        int sum =  node->val + sumL +sumR;
        maxSum = max(maxSum,sum);

        return node->val + max(sumL,sumR);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        helperSum(root, maxSum);
        return maxSum;
    }
};
