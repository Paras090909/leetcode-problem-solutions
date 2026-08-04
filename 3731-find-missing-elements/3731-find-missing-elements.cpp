class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minimumElement = *min_element(nums.begin(), nums.end());
        int maximumElement = *max_element(nums.begin(), nums.end());
        set<int>st;
        for(int value = minimumElement; value <= maximumElement; value++){
            st.insert(value);
        }
        for(int val : nums){
            st.erase(val);
        }
        vector<int>res;
        for(int it : st){
            res.push_back(it);
        }
        return res;
    }
};