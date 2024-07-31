class Solution {
public:
    int helper(string s,string t,int i,int j){
        // base
        if(j==0) return 1;
        if(i==0) return 0;
        // recursion
        if(s[i-1]==t[j-1]){
            return helper(s,t,i-1,j)+helper(s,t,i-1,j-1);
        }
        return helper(s,t,i-1,j);
    }
    int numDistinct(string s, string t) {
        //return helper(s,t,s.length(),t.length());
        int n = s.length();
        int m = t.length();
        const int mod = 1e9 + 7;
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));

        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }
};