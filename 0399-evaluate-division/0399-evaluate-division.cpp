class Solution {
public:
    void dfs(string src,string des, map<string,vector<pair<string,double>>>& mp,set<string>&visit,double &ans, double tmp){
        if(visit.find(src) != visit.end()){
            return;
        }
        if(src == des){
            ans = tmp;
            return;
        }
        
        visit.insert(src);
        for(auto x : mp[src]){
            dfs(x.first,des,mp,visit,ans,tmp*x.second);
        }
        return;
    }
    
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        map<string,vector<pair<string,double>>> mp;
        for(int i = 0; i<e.size(); i++){
            mp[e[i][0]].push_back({e[i][1],v[i]});
            mp[e[i][1]].push_back({e[i][0],1.0/v[i]});
        }
        
        vector<double>solve;
        
        for(int i = 0; i<q.size(); i++){
            string src = q[i][0];
            string des = q[i][1];
            
            double ans = -1.0;
            double tmp = 1.0;
            set<string>visit;
            if(mp.count(src)){
                dfs(src,des,mp,visit,ans,tmp);
            }
            solve.push_back(ans);
        }
        
        return solve;
        
    }
};