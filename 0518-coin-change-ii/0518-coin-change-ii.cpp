class Solution {
public:
    int helper(vector<int> coins,int i, int amt,vector<vector<int>> &dp){
        // base case
        if(i==0){
            if(amt%coins[0]==0) return 1;
            else return 0;
        }
        if(dp[i][amt]!=-1) return dp[i][amt];

        // recursive case
        int notTake=helper(coins,i-1,amt,dp);
        int take=0;
        if(coins[i]<=amt) take=helper(coins,i,amt-coins[i],dp);

        return dp[i][amt]=(take+notTake);
    }    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return helper(coins,coins.size()-1,amount,dp);
    }
};