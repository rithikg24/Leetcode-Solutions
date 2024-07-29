class Solution {
public:
    int helper(vector<int> nums,int i,int target,int res,unordered_map<int,unordered_map<int,int>> &hm){
        // base
        if(i==nums.size()){
            if(target==res){
                return hm[i][target]=1;
            }
            return hm[i][target]=0;
        }

        if(hm.count(i)==1 && hm[i].count(target)==1) return hm[i][target];

        // recursion
        int add=helper(nums,i+1,target+nums[i],res,hm);
        int sub = helper(nums,i+1,target-nums[i],res,hm);

        return hm[i][target]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,unordered_map<int,int>> hm;
        return helper(nums,0,0,target,hm);
    }
};