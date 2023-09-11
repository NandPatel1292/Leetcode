class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<vector<int>>ans;
        
        map<int,vector<int>>mp;
        
        for(int i = 0; i<g.size(); i++){
            int x = g[i];
            
            mp[x].push_back(i);
            
            if(mp[x].size() == x){
                ans.emplace_back(move(mp[x]));
                
                mp[x].clear();
            }
        }
        
        return ans;
    }
};