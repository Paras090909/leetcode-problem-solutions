class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                int val1 = nums[i]-1;
                int val2 = nums[j]-1;
                int sum = val1*val2;
                res = max(res, sum);
            }
        }
        return res;
    }
};