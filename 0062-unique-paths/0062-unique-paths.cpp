class Solution {

private:
    int solve(int i, int j, int m, int n, vector<vector<int>>&dp){
        //base
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;
        return dp[i][j] = solve(i+1, j, m, n, dp) + solve(i, j+1, m, n, dp);
    }

public:
    int uniquePaths(int m, int n) {
        int i = 0, j = 0;
        vector<vector<int>>dp(m+1);
        for(int i = 0; i <= m; i++){
            vector<int>t(n+1, -1);
            dp[i] = t;
        }

        return solve(i, j, m, n, dp);
    }
};