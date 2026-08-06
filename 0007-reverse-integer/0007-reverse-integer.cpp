class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        if(x == INT_MAX) return 0;
        long long  result = 0;
        int num = x;
        while(num !=0){
            int lastDigit = num%10;
            if(result*10 > INT_MAX || result*10 < INT_MIN) return 0;
            result = result*10+lastDigit;
           
            num/=10;
        }
        return result;
    }
};