class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c = 0;
        long long  ans = 0;
        
        for(auto &it: nums){
            if(it == 0){
                c++;
                ans += c;
            }
            else{
                c = 0;
            }
        }
        
        return ans;
        
    }
};