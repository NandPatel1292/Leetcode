class Solution {
public:
    int n,m;
    long long int dp[51][51][11];
    long long mod = 1e9 + 7;
    long long int cnt(int r, int c, int cut, vector<vector<int>>& apple){
        if(dp[r][c][cut] != -1){
            return dp[r][c][cut];
        }
        if(cut == 0){
            dp[r][c][cut] = (apple[r][c] > 0) ? 1 : 0;
            // if(apple[r][c] > 0){
            //     dp[r][c][cut] = 1;
            // }
            // else{
            //     dp[r][c][cut] = 0;
            // }
            return dp[r][c][cut];
        }
        long long int rsum = 0;
        long long int csum = 0;
        
        for(int i = r+1; i < n; i++){
            if(apple[r][c] - apple[i][c] > 0 && apple[i][c] >= cut){
                rsum = (rsum + cnt(i,c,cut-1,apple))%mod;
            }
        }
        
        for(int j = c+1; j < m; j++){
            if(apple[r][c] - apple[r][j] > 0 && apple[r][j] >= cut){
                csum = (csum + cnt(r,j,cut-1,apple))%mod;
            }
        }
        
        dp[r][c][cut] = rsum + csum;
        return dp[r][c][cut];
    }
    int ways(vector<string>& p, int k) {
        memset(dp,-1,sizeof(dp));
        n = p.size();
        m = p[0].size();
        vector<vector<int>> apple(n+1,vector<int>(m+1,0));
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j>= 0; j--){
                apple[i][j] = apple[i+1][j] + apple[i][j+1] - apple[i+1][j+1] + (p[i][j] == 'A');        
            }
        }
        long long int ans = cnt(0,0,k-1,apple);
        return ans;
    }
};