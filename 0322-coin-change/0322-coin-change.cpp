class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));

        for(int amt=0;amt<=amount;amt++){
            if(amt%coins[0]==0) dp[0][amt]=amt/coins[0];
            else{
                dp[0][amt]=1e9;
            }
        }

        for(int i=1;i<coins.size();i++){
            for(int amt=0;amt<amount+1;amt++){
                int notTake = dp[i-1][amt];
                int take=1e9;
                if(coins[i]<=amt) take=1+dp[i][amt-coins[i]];
                dp[i][amt]=min(notTake,take);
            }
        }

        int res=dp[coins.size()-1][amount];
        return res<1e9?res:-1;
    }
};