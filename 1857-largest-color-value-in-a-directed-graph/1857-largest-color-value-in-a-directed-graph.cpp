class Solution {
public:
    int largestPathValue(string color, vector<vector<int>>& edges) {
        int n = color.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        
        for(auto & i : edges){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        
        vector<vector<int>> cnt(n,vector<int>(26));
        queue<int> q;
        
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int ans = 0;
        int vnode = 0;
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans = max(ans,++cnt[x][color[x] - 'a']);
            vnode++;
            
            for(auto& m : adj[x]){
                for(int i = 0; i<26; i++){
                    cnt[m][i] = max(cnt[m][i], cnt[x][i]);
                }
            
            
                indegree[m]--;
                if(indegree[m] == 0){
                    q.push(m);
                }
            }
        }
        
        return vnode < n ? -1 : ans;
    }
};