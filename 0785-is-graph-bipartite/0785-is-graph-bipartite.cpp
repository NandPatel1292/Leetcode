class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        vector<int> v(g.size(),0);
        for(int i = 0; i<g.size(); i++){
            if(v[i] != 0){
                continue;
            }
            queue<int>q;
            q.push(i);
            v[i] = 1;
            
            while(!q.empty()){
                int tmp = q.front();
                q.pop();
                
                for(auto x : g[tmp]){
                    if(v[x] == 0){
                        v[x] = -v[tmp];
                        q.push(x);
                    }
                    else if(v[x] != -v[tmp]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};