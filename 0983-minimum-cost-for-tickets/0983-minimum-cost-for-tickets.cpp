class Solution {
public:
    
    int solve(int n,vector<int>&day,vector<int>&cost,int index,vector<int>&dp){
        if(index >= n){
            return 0;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }
        
        int op1 = cost[0] + solve(n,day,cost,index+1,dp);
        
        int i;
        for(i = index; i<n && day[i] < day[index]+7; i++);
        
        int op2 = cost[1] + solve(n,day,cost,i,dp);
        
        for(i = index; i<n && day[i] < day[index]+30; i++);
        
        int op3 = cost[2] + solve(n,day,cost,i,dp);
        
        dp[index] = min(op1,min(op2,op3));
        
        return dp[index];

    } 
    int mincostTickets(vector<int>& day, vector<int>& cost) {
        int n = day.size();
        vector<int>dp(n+1,-1);
        return solve(n,day,cost,0,dp);
    }
};