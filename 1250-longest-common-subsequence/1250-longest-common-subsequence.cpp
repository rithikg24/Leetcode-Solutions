class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));

        int len_a = text1.length();
        int len_b = text2.length();

        for(int i=1;i<=len_a;i++){
            for(int j=1;j<=len_b;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] =1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[len_a][len_b];
    }
};