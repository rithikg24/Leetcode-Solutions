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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> hm; // col, row - val
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* n = q.front().first;
            int col = q.front().second.first;
            int row = q.front().second.second;
            q.pop();
            if(!hm[col].count(row)){
                hm[col][row]={};
            }
            hm[col][row].push_back(n->val);
            if(n->left){
                q.push({n->left,{col-1,row+1}});
            }
            if(n->right){
                q.push({n->right,{col+1,row+1}});
            }
        }

        vector<vector<int>> res;

         for (auto& colPair : hm) {
            vector<int> colValues;
            for (auto& rowPair : colPair.second) {
                sort(rowPair.second.begin(), rowPair.second.end());
                colValues.insert(colValues.end(), rowPair.second.begin(), rowPair.second.end());
            }
            res.push_back(colValues);
        }

        return res;
    }
};