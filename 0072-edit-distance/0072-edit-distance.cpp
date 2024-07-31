class Solution {
public:
    int helper(string s,string t,int i,int j){
        // base
        if(j==0) return i;
        if(i==0) return j;

        // recursion
        if(s[i-1]==t[j-1]){
            return helper(s,t,i-1,j-1);
        }else{
            int rem = 1+helper(s,t,i-1,j);
            int rep = 1+helper(s,t,i-1,j-1);
            int ins = 1+helper(s,t,i,j-1);
            return min(rem,min(rep,ins));
        }
    }
    int minDistance(string word1, string word2) {
        //return helper(word1,word2,word1.length(),word2.length());
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int rem = 1+dp[i-1][j];
                    int rep = 1+dp[i-1][j-1];
                    int ins = 1+dp[i][j-1];
                    dp[i][j] = min(rem,min(rep,ins));
                }
            }
        }
        return dp[n][m];
    }
};