class Solution {
public:
    int minPairSum(vector<int>& n) {
        sort(n.begin(),n.end());
        
        int s = n.size();
        int mx = 0;
        for(int i = 0; i<s/2; i++){
            mx = max(mx,n[i]+n[s-i-1]);
        }
        
        return mx;
    }
};