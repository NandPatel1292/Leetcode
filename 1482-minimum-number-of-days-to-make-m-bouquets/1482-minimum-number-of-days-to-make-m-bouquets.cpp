class Solution {
public:
    int solve(vector<int>b , int mid, int k){
        int ans = 0;
        int c = 0;
        
        for(int i = 0; i<b.size(); i++){
            if(b[i] <= mid){
                c++;
            }
            else{
                c = 0;
            }
            
            if(c == k){
                ans++;
                c = 0;
            }
        }
        
        return ans;
    }
    
    int minDays(vector<int>& b, int m, int k) {
      
        
        int l = 0;
        int r = 0;
        
        for(auto i : b){
            r = max(r,i);
        }
        
        int ans = -1;
        while(l <= r){
            int mid = r + (l - r)/2;
            
            if(solve(b,mid,k) >= m){
                ans = mid;
                r = mid - 1;
                
            }
            else{
                l = mid +1;
            }
        }
        
        return ans;
    }
};