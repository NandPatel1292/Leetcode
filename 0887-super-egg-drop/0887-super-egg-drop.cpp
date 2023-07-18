class Solution {
public:
    
    int solve(int k, int n, vector<vector<int>>&dp){
        if(k == 1){
            return n;
        }
        if(n == 1 || n == 0){
            return n;
        }
        
        if(dp[k][n] != -1){
            return dp[k][n];
        }
        
        int ans = INT_MAX;
        
        int l = 1;
        int h = n;
        int tmp = 0;
        
        while(l <= h){
            int mid = l + (h - l)/2;
            int left = solve(k-1,mid-1,dp);
            int right = solve(k,n-mid,dp);
            tmp = 1 + max(left,right);
            if(left<right){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
            
            ans = min(ans,tmp);
        }
        
        // for(int i = 1; i<=n; i++){
        //     int low=0, high;
        //     if(dp[k-1][i-1] != -1){
        //         low = dp[k-1][i-1];
        //     }
        //     else{
        //         low = solve(k-1,i-1,dp);
        //         dp[k-1][i-1] = low;
        //     }
        //     if(dp[k][n-i] != -1){
        //         high = dp[k][n-i];
        //     }
        //     else{
        //         high = solve(k,n-i,dp);
        //         dp[k][n-i] = high;
        //     }
        //     int tmp = 1 + max(low,high);
        //     ans = min(ans,tmp);
        // }
        
        return dp[k][n] = ans;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};