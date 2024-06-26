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
        vector<int> res;
        if(!root) return res;
        queue<pair<TreeNode*,int>> q;
        unordered_map<int,int> hm; // row,val
        q.push({root,0});

        while(!q.empty()){
            TreeNode* n = q.front().first;
            int row = q.front().second;
            q.pop();
            if(!hm.count(row)){
                hm[row]=n->val;
                res.push_back(n->val);
            }
            if(n->right){
                q.push({n->right,row+1});
            }
            if(n->left){
                q.push({n->left,row+1});
            }
        }
        return res;
    }
};