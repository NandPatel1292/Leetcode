class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int mod = 1000000007;
        int alpha = 26;
        
        int m = target.size();
        int n = words[0].size();
        
        vector<vector<int>> c(alpha,vector<int>(n));
        // 
        for(int i = 0; i< n; i++){
            for(const string& x : words){
                c[x[i] - 'a'][i]++;
            }
        }
        vector<vector<long long>> dp(m+1,vector<long long>(n+1));
        // 
        dp[0][0] = 1;
        for(int i = 0; i<=m; i++){
            for(int j = 0; j<n; j++){
                if(i<m){
                    (dp[i+1][j+1] += c[target[i] - 'a'][j] * dp[i][j]) %= mod;
                }
                (dp[i][j+1] += dp[i][j])%= mod;
            }
        }
        return dp[m][n];
    }
};