class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>mp;
    vector<string>ans;
    
    void dfs(string s){
        auto &x = mp[s];
        while(!x.empty()){
            string z = x.top();
            x.pop();
            dfs(z);
        }
        
        ans.push_back(s);
    }    
    vector<string> findItinerary(vector<vector<string>>& t) {
        for(auto &x : t){
            mp[x[0]].push(x[1]);
            
        } 
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};