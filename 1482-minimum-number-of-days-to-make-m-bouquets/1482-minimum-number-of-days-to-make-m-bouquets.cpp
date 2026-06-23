class Solution {

private:
    bool check(vector<int> arr, int guess, int m, int k) {
        {
            int n = arr.size();
            int ans = 0, cnt = 0;

            for (int i = 0; i < n; i++) {
                if (arr[i] <= guess) { // flower has bloomed continue
                    cnt++;
                } else {
                    ans += (cnt / k); // if we can make a bouquet till this flower 
                    cnt = 0;
                }
            }

            ans += (cnt / k);

            return ans >= m;
        }
    }

public:
    int minDays(vector<int>& nums, int m, int k) {
        long long  n = nums.size();
        if (n < (long long )m * k) return -1;
        int minDays = *min_element(nums.begin(), nums.end());
        int maxDays = *max_element(nums.begin(), nums.end());
        int resDay = -1;
        while (minDays <= maxDays) {
            int guessDay = minDays + (maxDays - minDays) / 2;

            if (check(nums, guessDay, m, k)) {
                resDay =  guessDay;
                maxDays = guessDay - 1;
            } else {
                minDays = guessDay + 1;
            }
        }
        return resDay;
    }
};