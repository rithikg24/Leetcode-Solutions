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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // unordered_map<int,pair<int,int>> hm;
        unordered_map<int,TreeNode*> hm;
        set<int> childs;
        set<int> parents;
        for(vector<int> x:descriptions){
            int par=x[0];
            int child=x[1];
            int isleft=x[2];
            parents.insert(par);
            childs.insert(child);

            if(!hm.count(par)){
                hm[par]= new TreeNode(par);
            }
            if(!hm.count(child)){
                hm[child] = new TreeNode(child);
            }
            if(isleft==1){
                hm[par]->left=hm[child];
                
            }else{
                hm[par]->right=hm[child];
            }
        }
        int rootVal;
        for(int x:parents){
            if(childs.find(x)==childs.end()){
                return hm[x];
                break;
            }
        }

        return NULL;
    }
};