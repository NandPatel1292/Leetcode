class Solution {
public:
    // int dp[1001][2002];
    int solve(vector<vector<int>> &p, int k, int i,vector<vector<int>>&dp){
        if(i == p.size() || k == 0){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
       
        int mx = solve(p,k,i+1,dp);
        int sum = 0;
        for(int j = 0; j < min((int)p[i].size(),k); j++){
            sum += p[i][j];    
            mx = max(mx,sum + solve(p,k-j-1,i+1,dp));
            
        }
        
        return dp[i][k] = mx;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size(),vector<int>(k+1,-1));
        return solve(piles,k,0,dp);
    }
};