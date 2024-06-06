class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle[triangle.size()-1].size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            dp[i][0]=dp[i-1][0]+triangle[i][0];
            dp[i][i]=dp[i-1][i-1]+triangle[i][i];
        }
        for(int i=2;i<triangle.size();i++){
            for(int j=1;j<triangle[i].size()-1;j++){
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
            }
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            res=min(res,dp[n-1][i]);
        }
        return res;
    }
};