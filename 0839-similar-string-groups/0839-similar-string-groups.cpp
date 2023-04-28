class Solution {
public:
    void dfs(int i, vector<vector<int>>&adj, vector<int>&visit){
        visit[i] = 1;
        for(int x : adj[i]){
            if(!visit[x]){
                dfs(x,adj,visit);
            }
        }
    }
    
    bool similar(string&a, string&b){
        int c = 0;
        for(int i = 0; i<a.size(); i++){
            if(a[i] != b[i]){
                c++;
            }
        }
        
        return c == 0 || c == 2;
    }
    
    int numSimilarGroups(vector<string>& s) {
        int n = s.size();
        vector<vector<int>> adj(n+1);
        vector<int>visit(n+1);
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(similar(s[i],s[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            if(!visit[i]){
                dfs(i,adj,visit);
                ans++;
            }
        }
        
        return ans;
    }
};