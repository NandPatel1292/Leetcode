class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        vector<int>  ans;
        sort(p.begin(),p.end());
        
        int m = p.size();
        int mx = p[m - 1];
        
        for(auto i : s){
            long long mi = ceil((1.0* success)/i);
            
            if(mi > mx){
                ans.push_back(0);
                continue;
            }
            
            long long index = lower_bound(p.begin(),p.end(),mi) - p.begin();
            ans.push_back(m - index);
        }
        return ans;
    }
};