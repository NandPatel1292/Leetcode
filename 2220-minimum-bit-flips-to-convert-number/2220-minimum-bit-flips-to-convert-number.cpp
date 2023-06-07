class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = start ^ goal;
        int ans = 0;
        for(int i = 0; i<32; i++){
            int res1 = res >> i;
            if(res1&1){
                ans++;
            }
        }
        return ans;
    }
};