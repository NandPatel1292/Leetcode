class Solution {
public:
    
    void solve(int ind, vector<int>c, vector<int>op, int t, vector<vector<int>>&ans){
        if(ind == c.size()){
            if(t == 0){
                ans.push_back(op);
            }
            return;
        }
        
        if(c[ind] <= t){
            op.push_back(c[ind]);
            solve(ind,c,op,t-c[ind],ans);
            while(ind<c.size()-1 && c[ind]==c[ind+1]){
                ind++;                
            }
            op.pop_back();
        }
        
        solve(ind+1,c,op,t,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>>ans;
        vector<int>op;
        solve(0,c,op,t,ans);
        
        return ans;
    }
};