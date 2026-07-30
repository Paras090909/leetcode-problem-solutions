class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int res = 0;
        int i = 0;
        while(i < n && i < 8){
            res+=1;
            i++;
        }
        while(i < n && i < 16){
            res+=2;
            i++;
        }
        while(i< n && i < 24){
            res+=3;
            i++;
        }
        while(i < n && i < 26){
            res+=4;
            i++;
        }
        return res;
    }
};