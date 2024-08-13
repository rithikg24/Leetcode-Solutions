class Solution {
public:
    void helper(int i,int sum,vector<int> nums,vector<int> t, int target,vector<vector<int>> &res){
        if(sum==target){
            res.push_back(t);
            return;
        }
        if(i>=nums.size()) return;
        if(sum>target) return;

        
        // take
        if(sum+nums[i]<=target){
            t.push_back(nums[i]);
            helper(i+1,sum+nums[i],nums,t,target,res);
            t.pop_back();
        }

        // dont take
        i++;
        while(i-1>=0 && i<nums.size() && nums[i-1]==nums[i]){
            i++;
        }
        helper(i,sum,nums,t,target,res);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> st;
        helper(0,0,candidates,{},target,st);
        //vector<vector<int>> res(st.begin(),st.end());
        return st;
    }
};