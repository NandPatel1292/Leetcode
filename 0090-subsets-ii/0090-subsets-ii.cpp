class Solution {
public:
//     set<vector<int>>s;
//     void solve(vector<int> n, vector<int> tmp){
//         if(n.size() == 0){
//             s.insert(tmp);
//             return;
//         }
        
//         int x = n[n.size() - 1];
//         n.pop_back();
//         solve(n,tmp);
//         tmp.push_back(x);
//         solve(n,tmp);
//     }
    
    void solve(int ind, vector<int>n, vector<int>op, vector<vector<int>>&ans){
        if(ind == n.size()){
            ans.push_back(op);
            return;
        }
        
        op.push_back(n[ind]);
        solve(ind+1,n,op,ans);
        op.pop_back();
        while(ind < n.size()-1 && n[ind] == n[ind+1]){
            ind++;
        }
       
        
        solve(ind+1,n,op,ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(0,nums,tmp,ans);
        
        // for(auto i : s){
        //     ans.push_back(i);
        // }
        
        return ans;
    }
};