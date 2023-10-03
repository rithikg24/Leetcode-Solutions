class Solution {
public:
    void helper(vector<vector<int>> &res,vector<int> tmp,int sum,int k,int n,int i){
        if(sum==n && k==0){
            res.push_back(tmp);
            return;
        }
        if(k==0 || sum>n || i>9){
            return;
        }

        while(i<10){
            tmp.push_back(i);
            helper(res,tmp,sum+i,k-1,n,i+1);
            tmp.pop_back();
            i++;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        helper(res,{},0,k,n,1);
        return res;
    }
};