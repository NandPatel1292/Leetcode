class Solution {
public:
    int solve(int i, int j, vector<int> &c, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        
        
        int mi = INT_MAX;
        for(int k = i; k<= j; k++){
            int sum = c[j+1] - c[i-1] + solve(i,k-1,c,dp) + solve(k+1,j,c,dp);
            mi = min(mi,sum);
        }
        
        return dp[i][j] = mi;
    }
    
    int minCost(int n, vector<int>& c) {
        int s = c.size();
        
        c.push_back(n);
        c.insert(c.begin(),0);
        
        sort(c.begin(),c.end());
        vector<vector<int>> dp(s+1,vector<int> (s+1,-1));
        return solve(1,s,c,dp);
    }
};