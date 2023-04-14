class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        for(int i = n-1; i>=0; i--){
            vector<int>ndp(n,0);
            ndp[i] = 1;
            for(int j = i+1; j<n; j++){
                if(s[i] == s[j]){
                    ndp[j] = 2 + dp[j-1];
                    
                }
                else{
                    ndp[j] = max(dp[j],ndp[j-1]);
                }
            }
            dp = ndp;
        }
        return dp[n-1];
    }
};