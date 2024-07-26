class Solution {
public:
    int helper(int i,int j,vector<vector<int>> &dp){
        // base case
        if(i==0 || j==0) return dp[i][j]=1;

        if(dp[i][j]!=-1) return dp[i][j];


        // recursion
        int top=helper(i-1,j,dp);
        int left=helper(i,j-1,dp);
        return dp[i][j]=top+left;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        //return helper(m-1,n-1,dp);

        // base case
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int j=0;j<n;j++){
            dp[0][j]=1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int top=dp[i-1][j];
                int left=dp[i][j-1];
                dp[i][j]=top+left;
            }
        }

        return dp[m-1][n-1];
    }
};