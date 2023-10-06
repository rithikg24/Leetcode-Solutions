class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c:s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }else if(c==')'){
                if(st.empty()) return false;
                char x=st.top();
                st.pop();
                if(x!='('){
                    return false;
                }
            }else if(c=='}'){
                if(st.empty()) return false;
                char x=st.top();
                st.pop();
                if(x!='{'){
                    return false;
                }
            }else if(c==']'){
                if(st.empty()) return false;
                char x=st.top();
                st.pop();
                if(x!='['){
                    return false;
                }
            }
        }

        if(!st.empty()) return false;

        return true;

    }
};