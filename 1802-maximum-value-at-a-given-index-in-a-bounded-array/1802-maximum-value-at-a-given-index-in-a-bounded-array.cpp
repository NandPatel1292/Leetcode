class Solution {
public:
    long long sm(long long n){
        return( n*(n+1))/2;
    }
    
    
    int maxValue(int n, int index, int mx) {
        long long l = 1;
        long long r = mx;
        
        long long ans = 1;
        
        while(l <= r){
            long long mid = (r+l)/2;
            
            long long left = sm(mid-1);
            if(index > mid-1){
                left += (index-mid+1);
            }
            else{
                left -= sm(mid-1-index);
            }
            
            long long right = sm(mid-1);
            
            if((n-1-index) > (mid-1)){
                right += (n-1-index-(mid-1));
            }
            else{
                right -= sm(mid-1-(n-1-index));
            }
            
            if(left + right <= (mx-mid)){
                ans = mid;
                l = mid+1;
                
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};