class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int ans = INT_MAX;
        
        int n = nums.size();
        int cnt =0;
        // for(int i = 0; i<n; i++){
        //     int c = 1;
        //     int cnt = nums[i];
        //     if(cnt >= t){
        //         // ans = 1;
        //         ans = min(ans,c);
        //         continue;
        //     }
        //     for(int j = i+1; j<n; j++){
        //         cnt += nums[j];
        //         c++;
        //         if(cnt >= t){
        //             ans = min(ans,c);
        //             break;
        //         }
        //     }
        // }
        int c = 0;
        for(int i = 0; i<n; i++){
            cnt += nums[i];
            
            while(cnt >= t){
                ans = min(ans, i-c+1);
                cnt -= nums[c];
                c++;
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};