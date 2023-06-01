class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n = g.size();
        if(g[0][0] != 0 || g[n-1][n-1] != 0){
            return -1;
        }
            queue<pair<pair<int,int>,int>> q;
            vector<pair<int,int>> neig = {{-1,-1} ,{-1,0}, {-1,1},
                                          {0,-1},           {0,1},
                                          {1,-1} ,{1,0}, {1,1}};
            q.push({{0,0},1});
            g[0][0] = 1;
            while(!q.empty()){
                auto x = q.front();
                q.pop();
                int dis = x.second;
                int r = x.first.first;
                int c = x.first.second;
                
                if(r == n-1 && c == n-1){
                    return dis;
                }
                
                for(auto &it : neig){
                    int nr = r + it.first;
                    int nc = c + it.second;
                    
                    if(nr >= 0 && nr < n && nc >=0 && nc < n && g[nr][nc] == 0 ){
                        g[nr][nc] = 1;
                        q.push({{nr,nc},dis+1});
                    }
                }
            }
        return -1;
    }
};