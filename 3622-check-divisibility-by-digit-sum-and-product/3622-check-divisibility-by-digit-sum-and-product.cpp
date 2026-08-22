class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int digitSum = 0, digitProd = 1;
        while(num != 0){
            int ld = num%10;
            digitSum+=ld;
            digitProd*=ld;
            num/=10;
        }
        int total = digitSum+digitProd;
        if(n%total == 0){
            return true;
        }
        return false;
    }
};