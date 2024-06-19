class Solution {
public:
    int helper(vector<int> arr,int i,int j,vector<vector<int>> &dp){
        // base case
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        // recurrence
        int minSteps=-1e9;
        for(int k=i;k<=j;k++){
            int steps=(arr[i-1]*arr[k]*arr[j+1]) + helper(arr,i,k-1,dp) + helper(arr,k+1,j,dp);
            minSteps=max(minSteps,steps);
        }
        return dp[i][j]=minSteps;
    }
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+2,vector<int>(nums.size()+2,0));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        // return helper(nums,1,nums.size()-2,dp);

        for(int i=nums.size()-2;i>0;i--){
            for(int j=1;j<nums.size()-1;j++){
                if(i>j) continue;
                int minSteps=-1e9;
                for(int k=i;k<=j;k++){
                    int steps=(nums[i-1]*nums[k]*nums[j+1]) + dp[i][k-1] + dp[k+1][j];
                    minSteps=max(minSteps,steps);
                }
                dp[i][j]=minSteps;
            }
        }

        return dp[1][nums.size()-2];
    }
};