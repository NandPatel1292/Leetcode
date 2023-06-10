class Solution {
public:
    void solve(vector<int> &nums,vector<int> tmp, set<vector<int>>&s, int i){
        if(i == nums.size()){
            s.insert(tmp);
            return;
        }
        
        for(int x = i; x<tmp.size(); x++){
            swap(tmp[i],tmp[x]);
            solve(nums,tmp,s,i+1);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> tmp = nums;
        vector<vector<int>>ans;
        set<vector<int>>s;
        sort(tmp.begin(),tmp.end());
        solve(nums,tmp,s,0);
        
        for(auto i : s){
            ans.push_back(i);
        }
        
        return ans;
    }
};