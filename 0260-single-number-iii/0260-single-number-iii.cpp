class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        
        unordered_map<int,int>mp;
        for(auto i : nums){
            mp[i]++;
        }
        
        for(auto i : mp){
            if(ans.size() < 2 && i.second < 2){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};