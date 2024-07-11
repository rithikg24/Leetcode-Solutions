#include<stack>
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(char c:s){
            if(c==')'){
                string p="";
                while(st.top()!='('){
                    p+=st.top();
                    st.pop();
                }
                st.pop();
                for(char x:p){
                    st.push(x);
                }
            }else{
                st.push(c);
            }
        }
        string res="";
        while(!st.empty()){
            cout<<st.top()<<endl;
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};