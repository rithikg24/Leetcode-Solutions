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
    void inorder(TreeNode* root,int &sum){
        if(root){
            inorder(root->left,sum);
            sum+=root->val;
            inorder(root->right,sum);
        }
    }
    void resInorder(TreeNode* &root,int &prevsum,int tot){
        if(root){
            resInorder(root->left,prevsum,tot);
            int rv=root->val;
            root->val=tot-prevsum;
            prevsum+=rv;
            resInorder(root->right,prevsum,tot);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        int tot=0;
        inorder(root,tot);
        int prevsum=0;
        resInorder(root,prevsum,tot);
        return root;
    }
};