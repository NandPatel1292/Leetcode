class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],prob[i]});
            adj[edges[i][1]].push_back({edges[i][0],prob[i]});
        }
        
        vector<double>dis(n,0.0);
        dis[start] = 1.0;
        
        queue<int>q;
        q.push(start);
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            for(auto i : adj[x]){
                int node = i.first;
                double p = i.second;
                double np = dis[x]*p;
                
                if(np > dis[node]){
                    dis[node] = np;
                    q.push(node);
                }
            }
        }
        
        return dis[end];
    }
};