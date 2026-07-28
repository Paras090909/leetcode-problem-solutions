class Solution {
void solve(vector<int>& freq, string &res){
    int idx = 0;

    for(int i = 0; i < 26; i++){
        while(freq[i]--){
            res[idx++] = char(i + 'a');
        }
    }
}

public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        vector<int>freq(26, 0);

        for(int i = 0; i < n/2; i++){
            freq[s[i]-'a']++;
        }

        string res(n/2, '\0');
        solve( freq, res);
        string rev = res;
        reverse(rev.begin(), rev.end());
        if(n%2 == 0){
            return  res + rev;
        }else{
            return res + s[n/2]+rev;
        }
    }
};