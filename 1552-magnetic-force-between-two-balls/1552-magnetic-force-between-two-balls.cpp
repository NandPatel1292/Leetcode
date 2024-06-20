class Solution {
public:
    
    bool solve(int x, vector<int>&p, int m){
        int prv = p[0];
        int placed = 1;
        
        for(int i = 1; i<p.size() && placed < m; i++){
            int c = p[i];
            
            if(c - prv >= x){
                placed += 1;
                prv = c;
            }
        }
        
        return placed == m;
    }
    int maxDistance(vector<int>& p, int m) {
        int ans = 0;
        int n = p.size();
        sort(p.begin(),p.end());
        
        int l = 1;
        int r = ceil(p[n-1]/(m-1.0));
        
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(solve(mid,p,m)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid -1;
            }
        }
        
        return ans;
    }
};