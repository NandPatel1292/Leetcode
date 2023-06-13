class Solution {
public:
    int equalPairs(vector<vector<int>>& g) {
        int c = 0;
        int n = g.size();
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int f = 1;
                for(int k = 0; k<n; k++){
                    if(g[i][k] != g[k][j]){
                        f = 0;
                        break;
                    }
                }
                if(f){
                    c++;
                }
              
            }
        }
        
        return c;
    }
};