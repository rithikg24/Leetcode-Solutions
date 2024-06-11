class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);

        for(int amt=0;amt<=amount;amt++){
            if(amt%coins[0]==0) prev[amt]=amt/coins[0];
            else{
                prev[amt]=1e9;
            }
        }

        for(int i=1;i<coins.size();i++){
            for(int amt=0;amt<amount+1;amt++){
                int notTake = prev[amt];
                int take=1e9;
                if(coins[i]<=amt) take=1+curr[amt-coins[i]];
                curr[amt]=min(notTake,take);
            }
            prev=curr;
        }

        int res=prev[amount];
        return res<1e9?res:-1;
    }
};