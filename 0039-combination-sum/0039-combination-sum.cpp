class Solution {
public:
    void helper(vector<vector<int>> &res,vector<int>& candidates,vector<int> tmp,int target, int i){
        // base case
        if(i==candidates.size()){
            return;
        }
        if(target<0){
            return;
        }

        if(target==0){
            res.push_back(tmp);
            return;
        }

        // take
        tmp.push_back(candidates[i]);
        helper(res,candidates,tmp,target-candidates[i],i);


        // dont take
        tmp.pop_back();
        helper(res,candidates,tmp,target,i+1);

    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        helper(res,candidates,{},target,0);
        return res;
        
    }
};