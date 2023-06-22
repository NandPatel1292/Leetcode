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
    
    
    void solve2(int ind, vector<int>n, vector<vector<int>>&ans){
        if(ind == n.size()){
            ans.push_back(n);
            return;
        }
        
        for(int i = ind; i<n.size(); i++){
            swap(n[ind],n[i]);
            solve2(ind+1,n,ans);
            swap(n[ind],n[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& n) {
        vector<vector<int>>ans;
        vector<int>op;
        // solve(0,op,n,ans);
        solve2(0,n,ans);
        
        return ans;
    }
};