class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mn, int mx) {
        long long ans = 0;
        int mni = -1;
        int mxi = -1;
        int left = -1;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > mx || nums[i] < mn){
                left = i;
            }
            if(nums[i] == mn){
                mni = i;
            }
            if(nums[i] == mx){
                mxi = i;
            }
            
            ans += max(0,min(mni,mxi) - left);
        }
        return ans;
    }
};