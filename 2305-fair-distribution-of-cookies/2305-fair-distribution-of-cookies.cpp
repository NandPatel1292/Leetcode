class Solution {
public:
    // int ans;
    int solve(int ind, vector<int>&c, vector<int>&b){
        int k = b.size();
        if(ind == c.size()){
            int ans = 0;
            // int mx = INT_MIN;
            for(int j = 0; j<k; j++){
                ans = max(ans,b[j]);
            }
            // ans = min(ans,mx);
            return ans;
        }
        int mn = INT_MAX;
        for(int j = 0; j<k; j++){
            b[j] += c[ind];
            mn = min(solve(ind+1,c,b),mn);
            b[j] -= c[ind];
        }
        
        return mn;
    }
    
    int distributeCookies(vector<int>& c, int k) {
        vector<int>b(k,0);
        // ans = INT_MAX;
    
        return solve(0,c,b);
        
        // return ans;
    }
};