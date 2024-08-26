/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postOrder(Node* root,vector<int> &nodes){
        if(root){
            for(auto x:root->children){
                postOrder(x,nodes);
            }
            nodes.push_back(root->val);
        }
        
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        postOrder(root,res);
        return res;
    }
};