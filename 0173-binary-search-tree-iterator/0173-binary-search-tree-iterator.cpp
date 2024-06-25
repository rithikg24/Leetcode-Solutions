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
class BSTIterator {
public:
    vector<int> ino;
    int i=-1;
    void inorder(TreeNode* root,vector<int> &ino){
        if(root){
            inorder(root->left,ino);
            ino.push_back(root->val);
            inorder(root->right,ino);
        }
    }
    BSTIterator(TreeNode* root) {
        inorder(root,ino);
    }
    
    int next() {
        i++;
        return ino[i];
    }
    
    bool hasNext() {
        if(i+1<ino.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */