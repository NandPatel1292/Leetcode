class Solution {
public:
    
    int solve(vector<int> &s, int i,vector<int> &dp){
        if(i >= s.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        else{
            int ans = INT_MIN;
            ans = max(ans,s[i] - solve(s,i+1,dp));
            if(i+1 < s.size()){
                ans = max(ans,s[i] + s[i+1] - solve(s,i+2,dp));
            }
            if(i+2 < s.size()){
                ans = max(ans,s[i] + s[i+1] + s[i+2] - solve(s,i+3,dp));
            }
            
            return dp[i] = ans;
        }
    }
    
    string stoneGameIII(vector<int>& s) {
        vector<int> dp(s.size() + 1,-1);
        int a = solve(s,0,dp);
        if(a > 0){
            return "Alice";
        }
        if(a == 0){
            return "Tie";
        }
        return "Bob";
    }
};