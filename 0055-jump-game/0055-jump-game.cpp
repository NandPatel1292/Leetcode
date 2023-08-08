class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jmp = 0;
        for(int i = nums.size()-2; i>=0; i--){
            jmp++;
            if(nums[i] >= jmp){
                jmp = 0;
            }
        }
        if(jmp == 0){
            return true;
        }
        else{
            return false;
        }
    }
};