class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx;
        if(gain[0] >= 0){
            mx = gain[0];
        }
        else{
            mx = 0;
        }
        for(int i = 1; i<gain.size(); i++){
            gain[i] = gain[i] + gain[i-1];
            mx = max(mx,gain[i]);
        }
        
        return mx;
    }
};