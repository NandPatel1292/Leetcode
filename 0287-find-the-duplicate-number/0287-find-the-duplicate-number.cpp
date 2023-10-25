class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        unordered_map<int,int>mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        for(auto i : mp){
            if(i.second >= 2){
                ans = i.first;
            }
        }
        return ans;
    }
};