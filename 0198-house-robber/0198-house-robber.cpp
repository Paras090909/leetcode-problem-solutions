class Solution {

private:
    int solve(vector<int>&nums, int n, int i,int choice,  vector<vector<int>>&dp){
        // base case
        if(i == n) return 0;
        if(dp[i][choice] != -1) return dp[i][choice]; // memoization
        if(choice == 0) return dp[i][choice] = solve(nums, n, i+1, 1, dp); // if we have already robbed previous house then we have to skip this

        int c1 = nums[i] + solve(nums, n, i+1, 0, dp); // we want to rob this house -> include this in our answer
        int c2 = solve(nums, n, i+1, 1, dp); // we want to skip this house and thats why our choice is still 1 
        return max(c1,c2);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n);
        for(int i = 0; i < n; i++){
            vector<int>t(2, -1);
            dp[i] = t;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                cout<<"cell no " << i << " " << j << " " << " value " << dp[i][j];
            }
            cout<<endl;
        }
        int res = solve(nums, n, 0, 1, dp);
        return res;
    }
};