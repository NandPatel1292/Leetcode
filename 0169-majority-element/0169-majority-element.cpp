class Solution {
public:
    int majorityElement(vector<int>& nums) {
//         unordered_map<int,int>mp;
//         for(int i = 0; i<nums.size(); i++){
//             mp[nums[i]]++;
//         }
        
//         for(auto x : mp){
//             if(x.second > (nums.size()/2)){
//                 return x.first;
//             }
//         }
//         return -1;
        
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};