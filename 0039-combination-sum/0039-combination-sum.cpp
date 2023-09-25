class Solution {
public:
    void helper(vector<vector<int>> &res,vector<int> candidates,vector<int> temp,int s,int i){

        // base case
        if(s==0){
            res.push_back(temp);
            return;
        }
        if(s<0) return;

        // subtracting all numbers from s
        while(i<candidates.size()){
            temp.push_back(candidates[i]);
            helper(res,candidates,temp,s-candidates[i],i);
            temp.pop_back();
            i++;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        helper(res,candidates,{},target,0);
        return res;
    }
};