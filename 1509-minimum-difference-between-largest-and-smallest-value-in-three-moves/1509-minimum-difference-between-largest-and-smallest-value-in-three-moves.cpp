class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums.size()-4;
        
        int ans = INT_MAX;
        
        while(l < 4 || r < nums.size()){
            ans = min(ans,nums[r]-nums[l]);
            r++;
            l++;
        }
        
        return ans;
    }
};