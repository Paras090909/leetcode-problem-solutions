class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int n1 = nums[n-1] - 1;
        int n2 = nums[n-2]-1;
        int res = n1*n2;
        //res-=2;
        return res;
    }
};