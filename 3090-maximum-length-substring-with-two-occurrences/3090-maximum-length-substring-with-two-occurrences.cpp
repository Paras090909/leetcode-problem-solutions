class Solution {

private:
    bool check(vector<int>&mp){
        for(int i = 0; i < 26; i++){
            if(mp[i] > 2){
                return false;
            }
        }
        return  true;
    }

public:
    int maximumLengthSubstring(string s) {
        vector<int>mp(26, 0);
        int low = 0, high = 0, res = 0;

        while(high < s.size() && low <= high){
            mp[s[high]-'a']++;
            if(check(mp)){
                int len = high - low + 1;
                res = max(res, len);
            }else{
                mp[s[low]-'a']--;
                low++;
            }
            high++;
        }
        return res;
    }
};