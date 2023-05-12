class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n + 1, 0);
        
        for(int i = n-1; i>=0; i--){
            int p = q[i][0];
            int j = q[i][1];
            
            int nx = min(j+i+1,n);
            long long ans = p + dp[nx];
            dp[i] = max(ans,dp[i+1]);
        }
        
        return dp[0];
    }
};