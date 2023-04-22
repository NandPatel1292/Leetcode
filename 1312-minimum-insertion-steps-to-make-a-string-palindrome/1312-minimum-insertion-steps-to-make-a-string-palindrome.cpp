class Solution {
public:
    int solve(string &s, string&ss, int m, int n){
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        
        for(int i = 0; i<=m; i++){
            for(int j = 0; j<=n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(s[i-1] == ss[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                } 
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int minInsertions(string s) {
        int n = s.size();
        string ss = s;
        reverse(ss.begin(),ss.end());
        
        return n - solve(s,ss,n,n);
    }
};