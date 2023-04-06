class Solution {
public:
     void dfs(int i, int j, vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] != 0)
            return;

        g[i][j] = 1;
        dfs(i+1, j, g);
        dfs(i-1, j, g);
        dfs(i, j+1, g);
        dfs(i, j-1, g);
    }
    
    int closedIsland(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        
        for(int i = 0; i<m; i++ ){
            dfs(i,0,g);
            dfs(i,n-1,g);
        }
        
        for(int j = 0; j < n; j++){
            dfs(0,j,g);
            dfs(m-1,j,g);
        }
        
        int c = 0;
        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (g[i][j] == 0) {
                    dfs(i, j, g);
                    c++;
                }
            }   
        }
        return c;
    }
};