class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
       int m = text1.size(), n = text2.size();
       vector<vector<int>>dp(m+1);

       for(int i = 0; i<= m; i++){
        vector<int>t(n+1, -1);
        dp[i]= t;
       }
            // fill the last column
        for(int i = 0; i <= m; i++){
            dp[i][n] = 0;
        }
            // fill the last row
        for(int i = 0; i <= n; i++){
            dp[m][i] = 0;
        }

       for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(text1[i] == text2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
       }
       return dp[0][0];
    }
};