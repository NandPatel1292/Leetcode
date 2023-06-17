class Solution {
public:
    int solve(int ind, int prev, vector<int>&arr1,vector<int>&arr2,map<pair<int,int>,int>&dp){
        if(ind == arr1.size()){
            return 0;
        }
        
        if(dp.find({ind,prev}) != dp.end()){
            return dp[{ind,prev}];
        }
        
        int rl = 1e9;
        int nrl = 1e9;
        
        int x = upper_bound(arr2.begin(),arr2.end(),prev) - arr2.begin();
        if(x < arr2.size()){
            rl = 1 + solve(ind+1,arr2[x],arr1,arr2,dp);
        }
        
        if(arr1[ind] > prev){
            nrl = solve(ind+1,arr1[ind],arr1,arr2,dp);
        }
        
        return dp[{ind,prev}]  = min(rl,nrl);
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        map<pair<int,int>,int>dp;
        sort(arr2.begin(),arr2.end());
        int ans = solve(0,-1,arr1,arr2,dp);
        
        return ans >= 1e9 ? -1 : ans;
    }
};