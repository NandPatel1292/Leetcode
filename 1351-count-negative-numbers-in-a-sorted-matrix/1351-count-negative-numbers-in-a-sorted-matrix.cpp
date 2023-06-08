class Solution {
public:
    int countNegatives(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int c = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(g[i][j] < 0){
                    c++;
                }
            }
        }
        
        return c;
    }
};