class Solution {
public:
    int longestArithSeqLength(vector<int>& n) {
        int ans = 0;
        vector<unordered_map<int,int>>dp(n.size());
        
        for(int i= 0; i<n.size(); i++){
            for(int j = 0; j<i; j++){
                int dif = n[j] - n[i];
                if(dp[j].count(dif)){
                    dp[i][dif] = dp[j][dif] + 1;
                }
                else{
                    dp[i][dif] = 2;
                }
                ans = max(ans,dp[i][dif]);
            }
        }
        
        return ans;
    }
};