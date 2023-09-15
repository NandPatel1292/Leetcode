class Solution {
public:
    int dp[1001];
    
    int find(int a){
        if(dp[a]<0){
            return a;
        }
        
        return dp[a] = find(dp[a]);
    }
    
    void un(int a, int b){
        dp[a] = b;
    }
    
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size();
        for(int i = 0; i<n; i++){
            dp[i] = -1;
        }
        
        vector<pair<int,pair<int,int>>>adj;
        
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int x = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
                
                adj.push_back({x,{i,j}});
            }
        }
        
        sort(adj.begin(),adj.end());
        
        int sum = 0;
        
        for(int i = 0; i<adj.size(); i++){
            int a = find(adj[i].second.first);
            int b = find(adj[i].second.second);
            
            if(a != b){
                sum += adj[i].first;
                un(a,b);
            }
        }
        return sum;
    }
};