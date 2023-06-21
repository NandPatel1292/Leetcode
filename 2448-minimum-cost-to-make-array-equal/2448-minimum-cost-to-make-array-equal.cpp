class Solution {
public:
    long long minCost(vector<int>& n, vector<int>& c) {
        long long ans = INT_MAX;
        vector<pair<long,long>>v;
        for(int i = 0; i<n.size(); i++){
            v.push_back({n[i],c[i]});
        }
        
        sort(v.begin(),v.end());
        // for(auto x : v){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        vector<long long>pref(n.size()+1);
        pref[0] = v[0].second;
        for(int i = 1; i<n.size(); i++){
            pref[i] = v[i].second + pref[i-1];
        }
        // for(auto x : pref){
        //     cout<<x<<endl;
        // }
        
//         for i  = 0;
        long long total = 0;
        for(int i = 1; i<n.size(); i++){
            total += (v[i].second * (v[i].first - v[0].first));           
        }
        
        ans = total;
        
        for(int i = 1; i<n.size(); i++){
            int diff = v[i].first - v[i-1].first;
            total += pref[i-1]*diff;
            total -= (pref[n.size()-1] - pref[i-1])*diff;
            ans = min(ans,total);
        }
        
        return ans;
    }
};