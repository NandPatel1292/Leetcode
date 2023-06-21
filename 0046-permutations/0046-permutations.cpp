class Solution {
public:
    
    void solve(int ind, vector<int>op,vector<int>n, vector<vector<int>>&ans){
        if(ind == n.size()){
            ans.push_back(op);
            return;
        }
        
        for(int i = 0; i<n.size(); i++){
            if(find(op.begin(),op.end(),n[i]) == op.end()){
                op.push_back(n[i]);
                solve(ind+1,op,n,ans);
                op.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& n) {
        vector<vector<int>>ans;
        vector<int>op;
        solve(0,op,n,ans);
        
        return ans;
    }
};