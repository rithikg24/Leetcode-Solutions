class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string res="";

        for(char c:s){
            if(c=='('){
                if(!st.empty()){
                    res+=c;
                }
                st.push(c);
            }else if(c==')'){
                st.pop();
                if(!st.empty()){
                    res+=c;
                }
            }else{
                res+=c;
            }
        }
        return res;
    }
};