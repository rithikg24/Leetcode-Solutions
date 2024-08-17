class Solution {
public:
    long long helper(vector<vector<int>> points,int i,int j,vector<vector<int>> &dp){
        if(i==0) return dp[i][j]=points[0][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int newRow = i-1;
        long long res=INT_MIN;
        for(int p=0;p<points[0].size();p++){
            long long newVal = points[i][j]-abs(p-j)+helper(points,newRow,p,dp);
            res=max(res,newVal);
        }
        return dp[i][j]=res;
    }
    long long maxPoints(vector<vector<int>>& points) {
        vector<vector<long long>> dp(points.size(),vector<long long>(points[0].size(),0));
        long long ress=-1e9;
        for(int j=0;j<points[0].size();j++){
            dp[0][j]=points[0][j];
            ress=max(ress,dp[0][j]);
        }
        for(int i=1;i<points.size();i++){
            vector<long long> left(points[0].size(),0);
            vector<long long> right(points[0].size(),0);
            left[0]=dp[i-1][0];
            for(int j=1;j<points[0].size();j++){
                left[j]=max(left[j-1]-1,dp[i-1][j]);
            }
            right[points[0].size()-1]=dp[i-1][points[0].size()-1];
            for(int j=points[0].size()-2;j>=0;j--){
                right[j]=max(right[j+1]-1,dp[i-1][j]);
            }
            for(int j=0;j<points[0].size();j++){
                dp[i][j]=points[i][j]+max(left[j],right[j]);
                ress=max(ress,dp[i][j]);
            }
        }
        return ress;
    }
};