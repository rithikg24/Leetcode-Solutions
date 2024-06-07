class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                // i-1 <-> j-1,j,j+1
                int top = dp[i-1][j];
                int topLeft = j-1>=0 ? dp[i-1][j-1] : INT_MAX;
                int topRight = j+1<n ? dp[i-1][j+1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min(top,min(topLeft,topRight));
            }
        }
        int res = INT_MAX;
        for(int x:dp[n-1]){
            res = min(res,x);
        }

        return res;
    }
};