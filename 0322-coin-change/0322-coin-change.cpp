class Solution {
public:
    int coinChange(vector<int>& c, int a) {
        int n = c.size();
        vector<vector<int>>dp(n+1,vector<int>(a+1));
        
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=a; j++){
                if(j == 0){
                    dp[i][j] = 0;
                }
                if(i == 0){
                    dp[i][j] = INT_MAX - 1;
                }
            }
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=a; j++){
                if(c[i-1] <= j){
                    dp[i][j] = min(dp[i][j-c[i-1]]+1,dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return (dp[n][a] == INT_MAX-1) ? -1 : dp[n][a];
    }
};