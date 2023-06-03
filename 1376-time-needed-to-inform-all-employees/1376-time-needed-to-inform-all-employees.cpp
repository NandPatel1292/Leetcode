class Solution {

public:
        
    int ans = INT_MIN;
    void dfs(vector<int> adj[],int headID, vector<int>&time,int curr){
        ans = max(ans,curr);
        
        for(auto i : adj[headID]){
            dfs(adj,i,time,curr+time[headID]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& m, vector<int>& time) {
        vector<int> adj[n];
        
        for(int i = 0; i<n; i++){
            if(m[i] != -1){
                adj[m[i]].push_back(i);
            }
        }
        
//         queue<pair<int,int>> q;
//         q.push({headID,0});
        
//         while(!q.empty()){
//             auto x = q.front();
//             q.pop();
//             int head = x.first;
//             int t = x.second;
            
//             ans = max(ans,t);
            
//             for(auto &i : adj[head]){
//                 q.push({i,t+time[head]});
//             }
//         }
        
        
        dfs(adj,headID,time,0);
        
        return ans;
    }
};