class Solution {

private:
    int solve(vector<int>&nums, int n, int i, int prev, vector<vector<int>>&dp){
        // base
        if(i == n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        if(prev == -1 || nums[i] > nums[prev]){
            int c1 = 1 + solve(nums, n, i+1, i, dp);
            int c2 = solve(nums, n, i+1, prev, dp);
            return dp[i][prev+1] = max(c1, c2);
        }

        return dp[i][prev+1] = solve(nums, n, i+1, prev, dp);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1);
        for(int i = 0; i <= n; i++){
            vector<int>t(n+1, -1);
            dp[i] = t;
        }
        
        return solve(nums, n, 0, -1, dp);
    }
};