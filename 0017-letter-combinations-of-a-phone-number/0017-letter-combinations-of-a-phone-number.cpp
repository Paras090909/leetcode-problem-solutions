class Solution {

private:
    void solve(string digits, int idx, int n, vector<string>&res, unordered_map<char, string>mp, string &tmp){
        // base case
        if(idx == n){
            res.push_back(tmp);
            return;
        }

        char digit = digits[idx];
        string mappedChars = mp[digit];

        for(int i = 0; i < mappedChars.size(); i++){
            tmp.push_back(mappedChars[i]);
            solve(digits, idx+1, n, res, mp, tmp);
            tmp.pop_back();
        }
        return ;
    }

public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string>mp;
        mp['2'] = {"abc"};
        mp['3'] = {"def"};
        mp['4'] = {"ghi"};
        mp['5'] = {"jkl"};
        mp['6'] = {"mno"};
        mp['7'] = {"pqrs"};
        mp['8'] = {"tuv"};
        mp['9'] = {"wxyz"};
        vector<string>res;
        int idx = 0, n = digits.size();
        string tmp = "";
        solve(digits, idx, n, res, mp, tmp);
        return res;

        
    }
};