class Solution {
public:
    int addDigits(int n) {
        int sum = 0;
        while(n > 0){
            int rem = n%10;
            sum += rem;
            n /= 10;
            
            if(n == 0 && sum >= 10){
                n = sum;
                sum = 0;
            }
        }
        
        return sum;
    }
};