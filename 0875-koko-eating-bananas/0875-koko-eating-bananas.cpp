class Solution {

private:
        // this function will take O(n) time 
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
        int minSpeed = 1, maxSpeed = *max_element(piles.begin(), piles.end()); // maximum speed could be sum of all elems of vector but since we want a minimum possible speed -> the maximum possible speed limit would be max elem of vector , same as speed cannot be 0 
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