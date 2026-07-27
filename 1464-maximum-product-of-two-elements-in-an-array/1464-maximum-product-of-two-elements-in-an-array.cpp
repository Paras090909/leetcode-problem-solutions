class Solution {
public:
    int maxProduct(vector<int>& nums) {
       priority_queue<int, vector<int>, greater<int>> pq;
       int n = nums.size(), idx = 0;
       while(idx < 2){
        pq.push(nums[idx]);
        idx++;
       }
       while(idx < n){
        if(nums[idx] > pq.top()){
            pq.pop();
            pq.push(nums[idx]);
        }
        idx++;
       }

       int n1 = pq.top();
       pq.pop();
       n1 = n1-1;
       int n2 = pq.top();
       pq.pop();
       n2 = n2-1;
       int res = n1*n2;
       return res;
       

    }
};