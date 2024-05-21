class Solution {
public:
    void solve(vector<int>n, vector<vector<int>>&ans, vector<int>tmp){
        if(n.size() == 0){
            ans.push_back(tmp);
            return;
        }
           
        // vector<int> op1 = tmp;
        // vector<int> op2 = tmp;
        // op2.push_back(n[0]);
        int x = n[n.size() - 1];
        n.pop_back();
        solve(n, ans,tmp);
        tmp.push_back(x);
        solve(n,ans,tmp);
        
        // ans.push_back(tmp);
        
//         tmp.push_back(n[0]);
//         solve(n,ans,tmp);
//         tmp.pop_back();
//         solve(n,ans,tmp);
//         n.erase(n.begin()+0);

        
    }
    
    void solve2(int ind,vector<int>tmp,vector<int>n,vector<vector<int>>&ans){
        if(ind == n.size()){
            ans.push_back(tmp);
            return;
        }
        
        int x = n[ind];
        solve2(ind+1,tmp,n,ans);
        tmp.push_back(x);
        solve2(ind+1,tmp,n,ans);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
//         solve 1
        // vector<vector<int>> ans;
        // // int sz = nums.size();
        // vector<int> tmp;
        // // ans.push_back(tmp);
        // solve(nums,ans,tmp);
        // return ans;
        
//         solve 2
        // vector<vector<int>>ans;
        // vector<int>tmp;
        
        // solve2(0,tmp,nums,ans);
        // return ans;
        
        
//         solve 3
        vector<vector<int>>ans;
        int n = nums.size();
        
        ans.push_back({});
        
        for(int i = 0; i<n; i++){
            
            int s = ans.size();
            for(int j = 0; j<s; j++){
                vector<int> tmp = ans[j];
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        
        return ans;
    }
};