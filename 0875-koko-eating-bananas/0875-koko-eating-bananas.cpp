class Solution {

private:
    bool check(vector<int>& piles,int speed, int h, int n){
        long long count = 0;
        for(int i = 0; i < n; i++){
            count += piles[i]/speed;
            if(piles[i]%speed != 0){
                count++;
            }
        }
        return count <= h ? true : false;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1, maxSpeed = *max_element(piles.begin(), piles.end());
        int res = -1;
        int n = piles.size();
        while(minSpeed <= maxSpeed){
            int guessSpeed = minSpeed + (maxSpeed - minSpeed)/2;
            bool checkForCurrent = check(piles,guessSpeed,h, n);
            if(checkForCurrent){
                res = guessSpeed;
                maxSpeed = guessSpeed - 1;
            }else{
                minSpeed = guessSpeed + 1;
            }
        }
        return res;
    }
};