class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        string check;
        int first=0;
        if(x>y){
            check="ab";
        }else{
            check="ba";
            first=1;
        }
        int fc=0;
        for(char c:s){
            if(!st.empty()){
                if(st.top()==check[0] && c==check[1]){
                    fc++;
                    st.pop();
                    continue;
                }
            }
            st.push(c);
        }
        reverse(check.begin(),check.end());

        string s2="";

        while(!st.empty()){
            s2+=st.top();
            st.pop();
        }

        reverse(s2.begin(),s2.end());

        int sc=0;
        for(char c:s2){
            if(!st.empty()){
                if(st.top()==check[0] && c==check[1]){
                    sc++;
                    st.pop();
                    continue;
                }
            }
            st.push(c);
        }

        return fc*max(x,y)+sc*min(x,y);
    }
};