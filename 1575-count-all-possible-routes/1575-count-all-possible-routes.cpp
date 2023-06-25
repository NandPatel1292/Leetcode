class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>>dp;

    int solve(int start,int end, int fuel, vector<int>&l){
        if(fuel < 0){
            return 0;
            
        }
        
        if(~dp[fuel][start]){
            return dp[fuel][start];
        }
        
        int ans = (start == end);
        
        for(int i = 0; i<l.size(); i++){
            if(i != start){
                ans = (ans + solve(i,end,fuel - abs(l[start] - l[i]),l))%mod;
            }
        }
        
        return dp[fuel][start] = ans;
    }
    
    int countRoutes(vector<int>& l, int start, int finish, int fuel) {
        int n = l.size();
        dp.resize(fuel+1,vector<int>(n,-1));
        
        return solve(start,finish,fuel,l);
    }
};