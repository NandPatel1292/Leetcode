class Solution {
public:
    int solve(int ind, unordered_map<string,int>&mp, string s,vector<int>&dp){
        if(ind >= s.size()){
            return 0;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        string res = "";
        int mx = s.size();
        for(int i = ind; i<s.size(); i++){
            res.push_back(s[i]);
            int curr;
            if(mp.count(res)){
                curr = 0;
            }
            else{
                curr = res.size();
            }
            // int curr = (mp.count(res))? 0 : res.size();
            int nx = solve(i+1,mp,s,dp);
            mx = min(mx,nx+curr);
        }
        
        return dp[ind] = mx;
    }
    
    int minExtraChar(string s, vector<string>& d) {
        vector<int>dp(s.size(),-1);
        unordered_map<string,int>mp;
        for(auto x : d){
            mp[x]++;
        }
        
        return solve(0,mp,s,dp);
    }
};

