class Solution {
public:
    int dp[1000 + 1][1000 + 1];

    int solve(string s1,string s2, int n, int m){
        if(n == 0 || m == 0){
            return 0;
        }
        
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        
        if(s1[n-1] == s2[m-1]){
            return dp[n][m] =  1 + solve(s1,s2,n-1,m-1);
        }
        else{
            return dp[n][m] =  max(solve(s1,s2,n-1,m),solve(s1,s2,n,m-1));
        }
    }
    
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        
        for(int i = 0; i<= n; i++){
            for(int j = 0; j<= m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                
                else if(t1[i-1] == t2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
        
        
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // memset(dp, -1, sizeof(dp));  
        // return solve(t1,t2,n,m);
    }
};