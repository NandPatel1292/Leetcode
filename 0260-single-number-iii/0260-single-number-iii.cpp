class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        
//         unordered_map<int,int>mp;
//         for(auto i : nums){
//             mp[i]++;
//         }
        
//         for(auto i : mp){
//             if(ans.size() < 2 && i.second < 2){
//                 ans.push_back(i.first);
//             }
//         }
        
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size()-1){
            if(nums[i] == nums[i+1]){
                i+=2;
            }
            else{
               
                ans.push_back(nums[i]);
                 i++;
                if(ans.size() == 2){
                    return ans;
                }
                
            }
        }
        
        if(ans.size() == 1){
            ans.push_back(nums[nums.size()-1]);
        }
        
        return ans;
    }
};