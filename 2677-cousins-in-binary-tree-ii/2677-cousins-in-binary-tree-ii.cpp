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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        root->val=0;
        while(!q.empty()){
            vector<TreeNode*> nodes;
            int sum=0;
            int s=q.size();
            while(s--){
                TreeNode* node=q.front();
                q.pop();
                nodes.push_back(node);
                  if(node->left){
                    sum+=node->left->val;
                    q.push(node->left);
                }
                  if(node->right){
                    sum+=node->right->val;
                    q.push(node->right);
                }
            }
            for(auto it:nodes){
                int t=sum;
                if(it->left) t=t-it->left->val;
                if(it->right) t=t-it->right->val;
                if(it->left) it->left->val=t;
                if(it->right) it->right->val=t;
            }
        }
      return root;
    }
};