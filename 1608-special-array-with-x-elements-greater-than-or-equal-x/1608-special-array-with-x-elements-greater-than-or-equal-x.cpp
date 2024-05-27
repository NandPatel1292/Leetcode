class Solution {
public:
    int solve(int val, vector<int>&nums){
        int start = 0;
        int end = nums.size()-1;
        
        int ind = nums.size();
        
        while(start<=end){
            int mid = start + (end - start)/2;
            
            if(nums[mid] >= val){
                ind = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        
        return ind;
    }
    
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1 ; i<=n; i++){
            int x = solve(i, nums);
            
            if(n-x == i){
                return i;
            }
        }
        
        return -1;
    }
};