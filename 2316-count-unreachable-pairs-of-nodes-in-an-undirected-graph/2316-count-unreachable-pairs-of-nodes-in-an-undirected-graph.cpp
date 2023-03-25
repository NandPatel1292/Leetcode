class Solution {
public:
    int bfs(int n, vector<vector<int>>&adj, vector<int>&visit){
        queue<int>q;
        q.push(n);
        int c = 1;
        visit[n] = 1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto i : adj[x]){
                if(!visit[i]){
                    q.push(i);
                    visit[i] = 1;
                    c++;
                }
            }
        }
        return c;
    }
    
    long long countPairs(int n, vector<vector<int>>& e) {
        vector<vector<int>> adj(n+1);
        for(auto i : e){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int>visit(n,0);
        long long cluster = 0;
        long long ans = 0;
        long long rem = n;
        
        for(int i = 0; i<n; i++){
            if(!visit[i]){
                cluster = bfs(i,adj,visit);
                ans += (cluster * (rem - cluster));
                rem -= cluster;
            }
        }
        
        return ans;
    }
};