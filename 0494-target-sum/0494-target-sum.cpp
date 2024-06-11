class Solution {
public:
    
    int tabu2FindTarget(vector<int>&nums,int& target)
    {
            int sum = 0;
            for (int num : nums) {
             sum += num;
            }
            if (sum < target || -sum > target) {
                 return 0;
                }
            vector<int> dp(2 * sum + 1, 0);
            dp[sum] = 1;
            for (int num : nums) {
                vector<int> next(2 * sum + 1, 0);
                for (int i = 0; i < dp.size(); i++) {
                    if (dp[i] != 0) {
                    next[i + num] += dp[i];
                     next[i - num] += dp[i];
                    }
            }
        
             dp = next;
        }
            return dp[sum + target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int i=0,sum=0,count=0;
        // solveTarget(nums,target,i,sum,count);
        
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        // memoSolveTargetSum(nums,target,i,sum,count,dp);
        
        // cout<<dp[0][sum]<<endl;

        int ans2 = tabu2FindTarget(nums,target);// Tabulation 2
        return ans2 ;

    }
};
