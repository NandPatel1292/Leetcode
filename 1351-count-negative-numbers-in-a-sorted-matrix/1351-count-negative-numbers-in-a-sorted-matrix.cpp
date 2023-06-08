class Solution {
public:
    int countNegatives(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int c = 0;
        for(int i = 0; i<n; i++){
            int index = upper_bound(g[i].begin(),g[i].end(),0,greater<int>()) - g[i].begin();
            c += (m - index);
        }
        
        return c;
    }
};