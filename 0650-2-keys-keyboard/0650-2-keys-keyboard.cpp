class Solution {
public:
    int helper(int n, int d, int val, int k, vector<vector<vector<int>>>& dp) {
        if (n == k) return 1; // 0 steps are needed if we've reached the target
        
        if (n > k) return 1e9; // If we exceed the target, return a large value

        if (dp[n][d][val] != -1) return dp[n][d][val]; // Return memoized result

        int cp = 1e9;
        if (d == 1) {
            cp = 1 + helper(n, 0, n, k, dp); // Copy all and reset the paste flag
        }
        
        int ps = 1 + helper(n + val, 1, val, k, dp); // Paste the last copied value

        return dp[n][d][val] = min(cp, ps); // Store the result in dp table
    }

    int minSteps(int n) {
        if (n == 1) return 0; // If n is 1, no steps are needed
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(n + 1, -1)));
        return helper(1, 1, 1, n, dp);
    }
};