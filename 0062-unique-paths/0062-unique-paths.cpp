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
        return helper(m-1,n-1,dp);
    }
};