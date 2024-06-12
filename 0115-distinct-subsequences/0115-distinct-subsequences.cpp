class Solution {
public:
    int numDistinct(string s, string t) {
        const int mod = 1e9 + 7;
        vector<vector<long long>> dp(s.length()+1,vector<long long>(t.length()+1,-1));

        for(int j=0;j<t.length()+1;j++){
            dp[0][j]=0;
        }
        for(int i=0;i<s.length()+1;i++){
            dp[i][0]=1;
        }

        for(int i=1;i<s.length()+1;i++){
            for(int j=1;j<t.length()+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[s.length()][t.length()];
    }
};