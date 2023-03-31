class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector dp(n+1,vector(n,vector<int>(n)));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                dp[1][i][j] = (s1[i] == s2[j]);
            }
        }
        for(int k = 2; k<= n; k++){
            for(int i = 0; i<n+1 - k; i++){
                for(int j = 0; j< n+1 - k; j++){
                    for(int nl = 1; nl < k; nl++){
                        const vector<int>& dp1 = dp[nl][i];
                        const vector<int>& dp2 = dp[k - nl][i+nl];
                        dp[k][i][j] |= dp1[j] && dp2[j+nl];
                        dp[k][i][j] |= dp1[j + k - nl] && dp2[j];
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};