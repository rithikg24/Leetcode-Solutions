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
    void inorder(TreeNode* root,vector<int> &nodes){
        if(root){
            inorder(root->left,nodes);
            nodes.push_back(root->val);
            inorder(root->right,nodes);
        }
    }
    TreeNode* buildBST(vector<int> n,int i,int j){
        if(i<=j){
            int m=(i+j)/2;
            TreeNode* nd = new TreeNode(n[m]);
            nd->left=buildBST(n,i,m-1);
            nd->right=buildBST(n,m+1,j);
            return nd;
        }else{
            return NULL;
        }
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> n;
        inorder(root,n);
        return buildBST(n,0,n.size()-1);
    }
};