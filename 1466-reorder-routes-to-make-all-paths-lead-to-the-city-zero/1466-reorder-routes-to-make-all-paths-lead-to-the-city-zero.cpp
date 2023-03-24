class Solution {
public:
    int bfs(int n, vector<vector<pair<int,int>>>&adj){
        vector<int> visit(n+1,0);
        queue<int>q;
        q.push(0);
        visit[0] = 1;
        int cnt = 0;
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto& [i,s] : adj[x]){
                if(!visit[i]){
                    cnt+= s;
                    visit[i] = 1;
                    q.push(i);
                }        
            }
        }
        
        return cnt;
        
    }
    
    int minReorder(int n, vector<vector<int>>& c) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i : c){
            adj[i[0]].push_back({i[1],1});
            adj[i[1]].push_back({i[0],0});
        }
        return bfs(n,adj);
    }
};