class Solution {
public:
    int helper(string& s, int i, int j, vector<vector<int>>& memo) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (s[i] == s[j]) {
            memo[i][j] = 2 + helper(s, i + 1, j - 1, memo);
        } else {
            memo[i][j] = max(helper(s, i + 1, j, memo), helper(s, i, j - 1, memo));
        }
        return memo[i][j];
    }
    
    int longestPalindromeSubseq(string s) {
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

        return prev[text2.length()];
    }
};