class Solution {
public:
    int profitableSchemes(int n, int mi, vector<int>& g, vector<int>& p) {
        int mod = 1000000007;
        vector<vector<int>> dp(mi+1,vector<int>(n+1,0));
        dp[0][0] = 1;
        int k = g.size();
        for(int i = 0; i<k; i++){
            int x = p[i];
            int y = g[i];
            for(int j = mi; j>= 0; j--){
                for(int a = n-y; a>=0; a--){
                    int mip = min(mi,x+j);
                    dp[mip][a+y] += dp[j][a];
                    dp[mip][a+y] %= mod;
                }
            }
        }
        return accumulate(begin(dp[mi]),end(dp[mi]),0LL)%mod;
    }
};