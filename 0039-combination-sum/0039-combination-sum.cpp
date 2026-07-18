class Solution {

private:
    void solve(vector<int>& candidates,int idx, int n, int sum, int target, vector<vector<int>>&res, vector<int>&tmp){
        //base case
        if(idx == n){
            if(sum == target){
                res.push_back(tmp);
            }
            return;
        }
        // here we have 2 choices 
        // choice one -> we totally ignores this candidate

        solve(candidates, idx+1, n, sum, target, res, tmp);

        // choice 2 -> we can  add this candidate atleast one time
        if(sum + candidates[idx] <= target){
            tmp.push_back(candidates[idx]);
            sum += candidates[idx];
            solve(candidates, idx, n, sum, target, res, tmp);
            sum -= candidates[idx];
            tmp.pop_back();
        }
        return ;
    }


public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>tmp;
        int idx = 0, n = candidates.size();
        int sum = 0;
        solve(candidates, idx, n, sum, target, res, tmp);
        return res;
    }
};