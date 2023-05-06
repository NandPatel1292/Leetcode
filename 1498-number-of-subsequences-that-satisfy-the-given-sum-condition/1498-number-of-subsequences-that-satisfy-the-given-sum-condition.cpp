class Solution {
public:
    int numSubseq(vector<int>& num, int target) {
        int mod = 1e9 + 7;
        
        int n = num.size();
        int ans = 0;
        int l = 0;
        int r = n-1;
        sort(num.begin(),num.end());
        vector<int> v(n,1);
        for(int i = 1; i<n; i++){
            v[i] = v[i-1]*2%mod;
        }
            while(l <= r){
                if(num[l] + num[r] > target){
                    r--;
                }
                else{
                    ans = (ans + v[r - l++])%mod;
                    // l++;
                }
            }
        
        return ans;
    }
};