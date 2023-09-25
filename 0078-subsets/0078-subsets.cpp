class Solution {
public:
    void helper(vector<int> nums,vector<vector<int>> &res,int i,vector<int> t){
        if(i>=nums.size()) return;

        // Include nums[i]
        t.push_back(nums[i]);
        res.push_back(t);
        helper(nums,res,i+1,t);

        t.pop_back();
        helper(nums,res,i+1,t);

        // Not Include nums[i]

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        vector<int> t;
        helper(nums,res,0,t);
        return res;
    }
};