class Solution {
public:
    int minInsertions(string s) {
        string text1=s;
        string text2=s;
        reverse(text2.begin(),text2.end());
        vector<int> prev(text2.length()+1,0);
        vector<int> curr(text2.length()+1,0);
       
        for(int i=1;i<text1.length()+1;i++){
            curr[0]=0;
            for(int j=1;j<text2.length()+1;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j]=1+prev[j-1];
                }else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }

        return s.length()-prev[text2.length()];
    }
};