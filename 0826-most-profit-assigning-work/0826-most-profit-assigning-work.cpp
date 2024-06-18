class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pair<int,int>>v;
        v.push_back({0,0});
        int ans = 0;
        
        for(int i = 0; i<d.size(); i++){
            v.push_back({d[i],p[i]});
        }
        
        sort(v.begin(), v.end());
        for(int i = 0; i<v.size()-1; i++){
            v[i+1].second = max(v[i].second,v[i+1].second);
        }
        
        for(int i = 0; i<w.size(); i++){
            int x = w[i];
            
            int l = 0; 
            int r = v.size() - 1;
            int sum = 0;
            while(l <= r){
                int mid = r + (l-r)/2;
                
                if(v[mid].first <= x){
                    sum = max(sum, v[mid].second);
                    l = mid +1;
                }
                else{
                    r = mid -1;
                }
            }
            ans += sum;
        }
        
        return ans;
    }
};