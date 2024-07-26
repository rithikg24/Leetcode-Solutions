class Solution {
public:
    int helper(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &arr){
        // base case
        if(arr[i][j]==1) return dp[i][j]=0;
        if(i==0 && j==0 && arr[0][0]==1) return 0;
        if(i==0 && j==0 && arr[0][0]==0) return 1;
        if(i==0){
            return dp[0][j]=helper(0,j-1,dp,arr);
        }
        if(j==0){
            return dp[i][0]=helper(i-1,j,dp,arr);
        }

        if(dp[i][j]!=-1) return dp[i][j];


        // recursion
        int top=helper(i-1,j,dp,arr);
        int left=helper(i,j-1,dp,arr);
        return dp[i][j]=top+left;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n=arr[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp,arr);
    }
};