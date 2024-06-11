class Solution {
public:
    int helper(vector<int> coins,int i,int amt,vector<vector<int>> &dp){
        // base case
        if(i==0){
            if(amt%coins[i]==0) return amt/coins[i];
            return 1e9;
        }
        if(amt==0) return 0;

        if(dp[i][amt]!=-1) return dp[i][amt];

        // recursive case
        int notTake = helper(coins,i-1,amt,dp); // done taking
        int take=1e9;
        if(coins[i]<=amt) take = 1+helper(coins,i,amt-coins[i],dp);
        return dp[i][amt] =  min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int res=helper(coins,coins.size()-1,amount,dp);
        return res<1e9?res:-1;
    }
};