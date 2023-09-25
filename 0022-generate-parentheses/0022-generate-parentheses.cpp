class Solution {
public:
    void helper(string s,int open,int close,int n,vector<string> &res){

        // Base Condition
        if(close==n){
            res.push_back(s);
            return;
        }

        // Adding open parenthesis
        if(open<n){
            helper(s+'(',open+1,close,n,res);
        }

        // Adding close parenthesis
        if(close<open){
            helper(s+')',open,close+1,n,res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("",0,0,n,res);
        return res;
    }
};