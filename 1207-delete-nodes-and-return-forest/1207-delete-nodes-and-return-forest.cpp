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
    void postorder(TreeNode* &root,set<int> vals,vector<TreeNode*> &res){
        if(root){
            postorder(root->left,vals,res);
            postorder(root->right,vals,res);
            if(vals.find(root->val)!=vals.end()){
                if(root->left) res.push_back(root->left);
                if(root->right) res.push_back(root->right);
                root=NULL;
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        set<int> st(to_delete.begin(),to_delete.end());
        postorder(root,st,res);
        if(root) res.push_back(root);
        return res;
    }
};