class Solution {
public:
    
    int solve(vector<int>&n, int ind, int sum){
        if(ind == n.size()){
            return sum;
        }
        
        int s = solve(n, ind+1, sum ^ n[ind]);
        int sx = solve(n, ind+1, sum);
        
        return s + sx;
    }
    
    void solve2(int ind, vector<int>&n, vector<int>&tmp, vector<vector<int>>&ans){
        if(ind == n.size()){
            ans.push_back(tmp);
            return;
        }
        
        int x = n[ind];
        solve2(ind+1,n,tmp,ans);
        tmp.push_back(x);
        solve2(ind+1,n,tmp,ans);
    }
    
    int subsetXORSum(vector<int>& nums) {
        // return solve(nums,0,0);
        
        vector<vector<int>>ans;
        vector<int>tmp;
        
        solve2(0, nums, tmp, ans);
        int result = 0;
        for(auto i : ans){
            int sum = 0;
            for(auto j : i){
                sum ^= j;
            }
            result += sum;
        }
        
        return result;
    }
};