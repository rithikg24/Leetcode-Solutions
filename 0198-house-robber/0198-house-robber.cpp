class Solution {
public:
    int helper(int i,vector<int> nums,vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        // dont take
        int dt = helper(i+1,nums,dp);
        // take
        int tk = nums[i]+helper(i+2,nums,dp);
        return dp[i]=max(dt,tk);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
};