class Solution {
public:
    int helper(vector<int> prices,int i, int buy, int k,vector<vector<vector<int>>> &dp){
        // base case
        if(i>=prices.size()) return 0;
        if(k==0) return 0;

        if(dp[i][buy][k]!=-1)return dp[i][buy][k];

        // recursive case
        if(buy){
            return dp[i][buy][k]=max((0-prices[i])+helper(prices,i+1,0,k,dp), //i buy
            helper(prices,i+1,1,k,dp)); // i dont buy
        }else{
            return dp[i][buy][k]=max(prices[i]+helper(prices,i+1,1,k-1,dp),//i sell
            helper(prices,i+1,0,k,dp)); // i don't sell
        }

    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // return helper(prices,0,1,2,dp);

        for(int buy=0;buy<2;buy++){
            for(int k=0;k<3;k++){
                dp[prices.size()][buy][k]=0;
            }
        }
        for(int i=0;i<prices.size()+1;i++){
            for(int buy=0;buy<2;buy++){
                dp[i][buy][0]=0;
            }
        }

        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int k=1;k<3;k++){
                    if(buy){
                        dp[i][buy][k]=max((0-prices[i])+dp[i+1][0][k], //i buy
                        dp[i+1][1][k]); // i dont buy
                    }else{
                        dp[i][buy][k]=max(prices[i]+dp[i+1][1][k-1],//i sell
                        dp[i+1][0][k]); // i don't sell
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};