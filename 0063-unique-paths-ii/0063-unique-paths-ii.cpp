class Solution {

private:
    int solve(int i, int j, int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dp){
        // base
        if(i == m - 1 && j == n-1) return 1;
        if(i < 0 || i >= m || j < 0 || j >= n) return  0;
        if(grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] =  solve(i+1, j, m, n, grid, dp)+solve(i, j+1, m, n, grid, dp);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));

        int i = 0, j =0;
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        return solve(i, j, m, n, obstacleGrid, dp);
    }
};