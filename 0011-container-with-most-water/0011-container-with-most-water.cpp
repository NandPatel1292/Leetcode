class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = 0;
        int l = 0;
        int r = h.size()-1;
        while(l < r){
            ans = max(ans,min(h[l],h[r])*(r-l));
            h[l] < h[r] ? l++ : r--;
        }
        // for(int i = 0; i<h.size(); i++){
        //     for(int j = i+1; j<h.size(); j++){
        //         int sum = min(h[i],h[j])*(j-i);
        //         ans = max(ans,sum);
        //     }
        // }
        
        return ans;
    }
};