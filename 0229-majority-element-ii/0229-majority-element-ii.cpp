class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto i: nums){
            mp[i]++;
        }
        
        for(auto x : mp){
            if(x.second > nums.size()/3){
                ans.push_back(x.first);
            }
        }
        
        return ans;
    }
};