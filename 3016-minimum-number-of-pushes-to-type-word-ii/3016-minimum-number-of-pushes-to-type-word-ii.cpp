class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26, 0);
        for(char ch : word){
            freq[ch-'a']++;
        }

        
        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());
       for(int i = 0; i < 26; i++){
            cout<<char(i+'a') << freq[i]<<endl;
        }
        int res = 0;
        int i = 0;
       while(i < 8){
            while(freq[i]--){
            res+=1;
            }
            i++;
        }
        while(i < 16){
            while(freq[i]--){
            res+=2;
            }
            i++;
        }
        while(i < 24){
            while(freq[i]--){
            res+=3;
            }
            i++;
        }
        while(i < 26){
            while(freq[i]--){
            res+=4;
            }
            i++;
        }

        return res;
    }
};