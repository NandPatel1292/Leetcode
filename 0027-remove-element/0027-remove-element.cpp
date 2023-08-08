class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c = 0;
        int tmp;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != val){
                // tmp = nums[c];
                // nums[c] = nums[i];
                // nums[i] = tmp;
                swap(nums[i],nums[c]);
                c++;
            }
        }
        
        return c;
    }
};