class Solution {
public:
    int minDistance(string word1, string word2) {
        string s1=word1;
        string s2=word2;
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return (n+m)-2*dp[n][m];
    }
};