class Solution {
public:
    set<vector<int>>s;
    void solve(vector<int> n, vector<int> tmp){
        if(n.size() == 0){
            s.insert(tmp);
            return;
        }
        
        int x = n[n.size() - 1];
        n.pop_back();
        solve(n,tmp);
        tmp.push_back(x);
        solve(n,tmp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(nums,tmp);
        
        for(auto i : s){
            ans.push_back(i);
        }
        
        return ans;
    }
};