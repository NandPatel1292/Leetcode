class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0;
        int r = h.size()-1;
        int ans = 0;
        
        int mxleft = 0;
        int mxright = 0;
        
        while(l <= r){
            if(h[l] <= h[r]){
                if(h[l] >= mxleft){
                    mxleft = h[l];
                }
                else{
                    ans += (mxleft-h[l]);
                }
                l++;
            }
            else{
                if(h[r] >= mxright){
                    mxright = h[r];
                }
                else{
                    ans += (mxright-h[r]);
                }
                r--;
            }
        }
        return ans;
    }
};