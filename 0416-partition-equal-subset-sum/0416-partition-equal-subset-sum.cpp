class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x:nums) sum+=x;
        if(sum%2!=0) return false;

        int target = sum/2;

        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);

        prev[0]=true;

        if(nums[0]<=target) prev[nums[0]]=true;

        for(int i=1;i<nums.size();i++){
            curr[0]=true;
            for(int t=1;t<target+1;t++){
                int notTaken = prev[t];
                int taken = false;
                if(nums[i]<=t) taken=prev[t-nums[i]];
                curr[t]=(taken||notTaken);
            }
            prev=curr;
        }

        return prev[target];
    }
};