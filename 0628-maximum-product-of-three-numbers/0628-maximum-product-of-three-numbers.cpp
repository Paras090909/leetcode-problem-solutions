class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       int n = nums.size();
       int res = INT_MIN;
       for(int i = 0; i < n-2; i++){
        int j = i+1, k = n-1;
        while(j < k){
            int sum = nums[i]*nums[j]*nums[k];
            res = max(res, sum);
            j++;
            k--;
        }
       }
       return res;
    }
};