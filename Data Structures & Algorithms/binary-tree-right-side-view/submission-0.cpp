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

    vector<int> rightSideView(TreeNode* root) {

    vector<int> ans;

        if(!root) return ans;

    

    queue<TreeNode*> q;

    q.push(root);

        while(!q.empty())

        {

            int n=q.size();

             for(int i=0;i<n;i++){

            TreeNode* curr=q.front();

            q.pop();

           

           

                if(i==0) ans.push_back(curr->val);

                //pushing right before left, so at each level, the first in the queue is the right child (i==0)
                //so we get the right view
                //as we navigate the queue level by level
                if(curr->right) q.push(curr->right);

                 if(curr->left) q.push(curr->left);

                

            }

        }

        return ans;

    }

};


