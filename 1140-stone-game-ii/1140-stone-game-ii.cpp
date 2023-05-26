class Solution {
public:
    // vector<vector<int>> dp(101,vector<int>(201,-1));
        int dp[101][201];
    
     int help(int i, int m,vector<int> &p){
            int n = p.size();
            if(i >= n){
                return 0;
            }
            
            if(dp[i][m] != -1){
                return dp[i][m];
            }
            
            int res = INT_MIN;
            int sum = 0;
            
            
            
            for(int j = 0; j< 2*m; j++){
                if(i+j < n){
                    sum += p[i+j];
                }
                
                res = max(res, sum - help(i+j+1,max(m,j+1),p));
            }
            
            return dp[i][m] = res;
        }
    
    int stoneGameII(vector<int>& p) {
       memset(dp,-1,sizeof dp);
       int sum = 0;
        for(auto x : p){
            sum += x;
        }
        
        int dif = help(0,1,p);
        
        
       
        return (sum+dif)/2;
    }
};