class Solution {

// void solve(string s,vector<int>freq, string &res, int n){
//     bool insertAtLast = 0;
//     int left = 0, right = res.size()-1;
//     for(int i = 0; i < 26; i++){
//         int charFreq = freq[i];
//         if(charFreq == 1){
//             res[n/2] = char(i + 'a');
//         }
//         else{ 
//         while(charFreq--){
//             if(insertAtLast){
//                 if(res[right] == '\0'){
//                 res[right] = char(i + 'a');
//                 right--;
//                 }  
//                 insertAtLast = 1 - insertAtLast;
//             }else{
//                 if(res[right] == '\0'){
//                 res[left] = char(i+'a');
//                 left++;
//                 }
//                 insertAtLast = 1 - insertAtLast;
//             }
//         }
//         }
//     }
// }

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