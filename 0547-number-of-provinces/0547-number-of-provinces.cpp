class Solution {
public:
    void bfs(int i, vector<vector<int>>&v, vector<int>&visit){
        queue<int>q;
        q.push(i);
        visit[i] = 1;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            
            for(int j = 0; j<v.size(); j++){
                if(v[x][j] && !visit[j]){
                    q.push(j);
                    visit[j] = 1;
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        int ans = 0;
        vector<int> visit(n,0);
        
        for(int i = 0; i<n; i++){
            if(!visit[i]){
                ans++;
                bfs(i,v,visit);
            }
        }
        
        return ans;
    }
};