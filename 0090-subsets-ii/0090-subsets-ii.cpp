class Solution {
public:
    void helper(set<vector<int>> &res,vector<int> t,vector<int> nums,int i){
        // base case
        if(i==nums.size()){
            res.insert(t);
            return;
        }

        // add element
        t.push_back(nums[i]);
        helper(res,t,nums,i+1);

        // not add element
        t.pop_back();
        helper(res,t,nums,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> r;
        vector<vector<int>> res;

        sort(nums.begin(),nums.end());

        helper(r,{},nums,0);

        for(auto x:r){
            res.push_back(x);
        }

        return res;
    }
};