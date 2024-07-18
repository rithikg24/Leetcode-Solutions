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
    vector<int> postorder(TreeNode* root,int distance,int &cnt){
        if(root){
            vector<int> lt = postorder(root->left,distance,cnt);
            vector<int> rt = postorder(root->right,distance,cnt);
            if(lt.size()==0 && rt.size()==0) return {1};
            if(lt.size()==0){
                for(int i=0;i<rt.size();i++){
                    rt[i]++;
                }
                return rt;
            }
            if(rt.size()==0){
                for(int i=0;i<lt.size();i++){
                    lt[i]++;
                }
                return lt;
            }
            for(int i=0;i<lt.size();i++){
                for(int j=0;j<rt.size();j++){
                    int d = lt[i]+rt[j];
                    if(d<=distance) cnt++;
                }
            }
            lt.insert(lt.end(),rt.begin(),rt.end());
            for(int i=0;i<lt.size();i++){
                lt[i]++;
            }
            return lt;

        }else{
            return {};
        }
    }
    
    int countPairs(TreeNode* root, int distance) {
       int cnt=0;
       postorder(root,distance,cnt);
       return cnt;
    }
};