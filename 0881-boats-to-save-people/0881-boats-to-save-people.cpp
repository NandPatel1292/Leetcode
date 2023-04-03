class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        
        int ans = 0;
        int right = p.size()-1;
        int left = 0;
        
        while(left<=right){
            if(p[left] + p[right] <= limit){
                left++;
                // right--;
            }
            
            right--;
            ans++;
        }
        return ans;
    }
};