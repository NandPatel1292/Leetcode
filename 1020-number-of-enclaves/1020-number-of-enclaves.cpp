class Solution {
public:
    int numEnclaves(vector<vector<int>>& g) {
        queue<pair<int,int>>q;
        
        int m = g.size();
        int n = g[0].size();
        
        vector<vector<int>> v(m,vector<int>(n,0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(g[i][j] == 1){
                        q.push({i,j});
                        v[i][j] =1;
                    }
                }
            }
        }
        vector<int> delr{-1,0,+1,0};
        vector<int> delc{0,+1,0,-1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = row + delr[i];
                int ncol = col + delc[i];
                
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol< n && v[nrow][ncol] == 0 && g[nrow][ncol] == 1 ){
                    q.push({nrow,ncol});
                    v[nrow][ncol] = 1;
                }
            }
        }
        
        int c = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(g[i][j] == 1 && v[i][j] == 0){
                    c++;
                }
            }
        }
        return c;
    }
};