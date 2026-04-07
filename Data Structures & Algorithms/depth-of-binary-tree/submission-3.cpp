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

//dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0 ;
        int maxD = 1+ max(maxDepth(root->left),maxDepth(root->right));
        return maxD;
    }
};



//level order traversal
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//        if(!root) return 0;
//        queue<TreeNode*> q;
//        int depth = 0;
       
//        q.push(root);
//        while(!q.empty()){
//         int qsize = q.size();
//         for(int i=0;i<qsize;i++){
//         TreeNode* curr  = q.front();
//         q.pop();
//         if(curr->left) q.push(curr->left);
//         if(curr->right) q.push(curr->right);
//         }
//         depth++;
        
        

//        }

//        return depth;

//     }
// };
