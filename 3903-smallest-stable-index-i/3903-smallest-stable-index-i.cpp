class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maximum(n, 0);
        maximum[0] = nums[0];
        int currmax = maximum[0];
        vector<int>minimum(n, 0);
        minimum[n-1] = nums[n-1];
        int currmin = minimum[n-1];
        for(int i = 1; i < n; i++){
            currmax = max(currmax, nums[i]);
            maximum[i] = currmax;
        }

        for(int i = n-2; i>=0; i--){
            currmin = min(currmin, nums[i]);
            minimum[i] = currmin;
        }
        int res = 1e8;
        for(int i = 0; i < n; i++){
            int diff = maximum[i]-minimum[i];
            if(diff <= k){
               return i;
            }
        }
        if(res == 1e8) return -1;
        return res;
    }
};