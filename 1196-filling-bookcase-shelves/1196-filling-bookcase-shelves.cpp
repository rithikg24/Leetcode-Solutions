class Solution {
public:
    int sw;
    int helper(vector<vector<int>>& books,int i,int rem,int mh,vector<vector<int>> &dp){
        // base
        if(i>=books.size()){
            return mh;
        }

        if(dp[i][rem]!=-1) return dp[i][rem];

        int w = books[i][0];
        int h = books[i][1];

        // recursion
        int same = INT_MAX;
        if(w<=rem){
            same=helper(books,i+1,rem-w,max(mh,h),dp);
        }
        int bot = mh + helper(books,i+1,sw-w,h,dp);
        return dp[i][rem]=min(same,bot);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        sw=shelfWidth;
        vector<vector<int>> dp(books.size(),vector<int>(shelfWidth+1,-1));
        return helper(books,0,shelfWidth,0,dp);
    }
};