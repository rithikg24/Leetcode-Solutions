class Solution {
public:
     int solve(vector<vector<int>>& grid, int i, int j, int prev, vector<vector<int>> &dp) {
    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return 0;
    }
    if (prev >= grid[i][j]) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int op1 = solve(grid, i - 1, j + 1, grid[i][j], dp);
    int op2 = solve(grid, i, j + 1, grid[i][j], dp);
    int op3 = solve(grid, i + 1, j + 1, grid[i][j], dp);

    return dp[i][j] = 1 + max({op1, op2, op3});
}

int maxMoves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    vector<vector<int>> dp(n , vector<int>(m , -1));
    for (int i = 0; i < n; i++) {
        int temp = solve(grid, i, 0, 0, dp);
        ans = max(ans, temp);
    }

    return ans - 1;
}
};