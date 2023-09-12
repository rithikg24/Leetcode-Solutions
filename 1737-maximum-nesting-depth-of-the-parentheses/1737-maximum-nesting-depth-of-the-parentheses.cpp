class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxCnt=0;
        int cnt=0;
        for(char c:s){
            if(c=='('){
                st.push('(');
                cnt++;
                maxCnt=max(maxCnt,cnt);
            }else if(c==')'){
                st.pop();
                cnt--;
                maxCnt=max(maxCnt,cnt);
            }
        }
        return maxCnt;
    }
};