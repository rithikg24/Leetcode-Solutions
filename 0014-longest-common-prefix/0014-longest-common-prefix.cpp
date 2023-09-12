class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i;
        int minLen=INT_MAX;
        for(string c:strs){
            if(minLen>c.size()){
                minLen=c.size();
            }
        }
        for(i=0;i<minLen;i++){
            char c=strs[0][i];
            int d=0;
            for(string s:strs){
                if(s[i]!=c){
                    d=1;
                    break;
                }
            }
            if(d==1){
                break;
            }
        }
        return strs[0].substr(0,i);
    }
};