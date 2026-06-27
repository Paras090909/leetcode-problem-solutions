class Solution {

private:
    bool helper(vector<int>& candies,int mid,  long long k){
        long long count = 0;
        int n = candies.size();
        for(int i = 0; i < n; i++){
            count += candies[i]/mid;
        }
        return  count >= k;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        //if(k > n) return 0;
        int low = 1;
        long long sum =0;
        for(int x : candies){
            sum+=x;
        }
        long long high = sum/k;
        int res = -1;
        while(low <= high){
            int mid = low + (high - low ) / 2;

            if(helper(candies, mid, k)){
                res = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return res == -1 ? 0 : res; 
    }
};