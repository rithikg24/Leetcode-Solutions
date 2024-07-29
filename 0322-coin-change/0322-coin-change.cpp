class Solution {
public:
    int helper(vector<int> coins,int i,int amt,vector<vector<int>> &dp){
        // base case
        
        if(i==0){
            if(amt%coins[0]!=0) return dp[i][amt]=1e9;
            return dp[i][amt]=amt/coins[0];
        }
        if(dp[i][amt]!=-1) return dp[i][amt];

        // recursion
        // take
        int take = 1e9;
        if(amt-coins[i]>=0){
            take = 1+helper(coins,i,amt-coins[i],dp);
        }
        int dt = helper(coins,i-1,amt,dp);
        return dp[i][amt]=min(take,dt);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        // int res=helper(coins,coins.size()-1,amount,dp);
        // return res>=1e9? -1:res;

        for(int amt=0;amt<amount+1;amt++){
            if(amt%coins[0]!=0){
                dp[0][amt]=1e9;
            }else{
                dp[0][amt]=amt/coins[0];
            }
        }

        for(int i=1;i<coins.size();i++){
            for(int amt=0;amt<amount+1;amt++){
                int take = 1e9;
                if(amt-coins[i]>=0){
                    take = 1+dp[i][amt-coins[i]];
                }
                int dt = dp[i-1][amt];
                dp[i][amt]=min(take,dt);
            }
        }

        int res = dp[coins.size()-1][amount];
        return res>=1e9?-1:res;
    }
};