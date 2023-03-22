class Solution {
public:
    int bfs(int n, vector<vector<pair<int,int>>>&adj){
        vector<int>visit(n+1);
        queue<int>q;
        int ans = INT_MAX;
        
        q.push(1);
        visit[1] = 1;
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            for(auto & i : adj[x]){
                ans = min(ans,i.second);
                if(!visit[i.first]){
                    visit[i.first] = 1;
                    q.push(i.first);
                }
            }
        }
        return ans;
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto & i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        return bfs(n,adj);
    }
};