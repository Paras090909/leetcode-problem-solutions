class Solution {
public:
    int maxProduct(int n) {
       int largestDigit = 0;
       int secondLargest = 0;
       while(n > 0){
        int lastDigit = n%10;
        if(lastDigit >= largestDigit){
           secondLargest = largestDigit;
            largestDigit = lastDigit;
        }
        else if(lastDigit > secondLargest && lastDigit != largestDigit){
            secondLargest = lastDigit;
        }
        n/=10;
       }
       return largestDigit*secondLargest;
       
    }
};