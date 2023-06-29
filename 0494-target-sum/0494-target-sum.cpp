class Solution {
public:
    int solve(int ind, vector<int>&n,int tar, vector<vector<int>>&dp,int sum){
        if(ind == n.size()){
            if(tar == sum){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(dp[ind][sum+1000] != -1){
            return dp[ind][sum+1000];
        }
        
        int l = solve(ind+1,n,tar,dp,sum+n[ind]);
        int r = solve(ind+1,n,tar,dp,sum-n[ind]);
        
        return dp[ind][sum+1000] = l + r;
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        vector<vector<int>> dp(nums.size()+1,vector<int>(2004+1,-1));
        return solve(0,nums,target,dp,sum);
    }
};