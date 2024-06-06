class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int j=0;

        for(int i=0;i<nums.size();i++){
            while(j<i){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
                j++;
            }
            j=0;
        }
        int res=INT_MIN;
        for(int x:dp){
            res=max(x,res);
        }

        return res;
    }
};