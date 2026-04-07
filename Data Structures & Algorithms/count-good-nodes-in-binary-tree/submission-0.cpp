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

    void DFS(TreeNode* node, int maxYet, int& count){
        TreeNode* curr = node;

        if(curr==NULL) return ;

        if(curr->val>=maxYet)  {
            count++;
            maxYet=curr->val;
        }
        DFS(curr->left, maxYet,count);

        DFS(curr->right, maxYet,count);


        
    }
    int goodNodes(TreeNode* root) {
       if(!root) return 0;
       TreeNode* node = root;
       int count=0;
       int maxYet = root->val;
       DFS(node,maxYet,count);
       return count;
    }
};
