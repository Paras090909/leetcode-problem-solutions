class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans_array(n,1);

        for(int i = 0; i < n; i++){
           // ans_array[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && ans_array[i] < ans_array[j]+1){
                    ans_array[i] = max(ans_array[i], ans_array[j]+1);
                }
            }
        }
        for(int num : ans_array){
            cout<<num<<endl;
        }
        int ans = *max_element(ans_array.begin(), ans_array.end());
        return ans;
    }
};