class Solution {
public:
    void bfs(int n,vector<int>&visit,vector<vector<int>>&adj){
        // queue<int>q;
        // q.push(n);
        visit[n] = 1;
        
        // while(!q.empty()){
            // int x = q.front();
            // q.pop();
            for(auto i: adj[n]){
                if(!visit[i]){
                    visit[i] = 1;
                    bfs(i,visit,adj);
                    // q.push(i);
                }
            }
        // }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& c) {
        if(c.size() < n-1){
            return -1;
        }
        vector<vector<int>> adj(n+1);
        for(auto& i:c){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int>visit(n+1,0);
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(!visit[i]){
                cnt++;
                bfs(i,visit,adj);
            }
        }
        
        return cnt-1;
    }
};