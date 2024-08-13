/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        queue<pair<Node*,int>> q;
        q.push({root,0});
        Node* prev=NULL;
        while(!q.empty()){
            Node* t=q.front().first;
            int lev = q.front().second;
            q.pop();
            // if(!q.empty() && q.front().second==lev){
            //     prev=t;
            // }else{
            //     prev=NULL;
            // }
            if(prev){
                prev->next=t;
            }
            if(!q.empty() && q.front().second==lev){
                prev=t;
            }else{
                prev=NULL;
            }
            if(t->left){
                q.push({t->left,lev+1});
            }
            if(t->right){
                q.push({t->right,lev+1});
            }
        }
        return root;
    }
};