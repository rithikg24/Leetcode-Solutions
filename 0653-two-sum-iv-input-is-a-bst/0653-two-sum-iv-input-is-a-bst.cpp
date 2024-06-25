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
    void inorder(TreeNode* root,vector<int> &ino){
        if(root){
            inorder(root->left,ino);
            ino.push_back(root->val);
            inorder(root->right,ino);
        }
    }
    bool twoSum(vector<int> nums,int target){
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int s = nums[i]+nums[j];
            if(s>target){
                j--;
            }else if(s<target){
                i++;
            }else{
                return true;
            }
        }

        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root,nums);
        return twoSum(nums,k);
    }
};