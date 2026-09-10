class Solution {

private:
    int solve(int i, int n, unordered_map<int, int>&mp){
        // base case
        if(i == n) return 1;
        if(i > n) return 0;

        if(mp.find(i) != mp.end()) return mp[i];
        int a1 = solve(i+1, n, mp);
        int a2 = solve(i+2, n, mp);
        int ans = a1+a2;
        mp[i] = ans;
        return ans;
    }

public:
    int climbStairs(int n) {
        // base case 
        unordered_map<int, int>mp;
        if(n == 1) return 1;
        int i = 0;
        int res = solve(i, n, mp);
        return res;
    }
};