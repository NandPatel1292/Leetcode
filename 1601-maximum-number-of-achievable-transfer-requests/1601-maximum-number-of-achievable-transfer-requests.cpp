class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& r) {
        int len = r.size();
        int total = pow(2,len);
        int mx = 0;
        
        vector<int> ans;
        for(int i = 0; i <= total; i++){
            vector<int> req;
            for(int j = 0; j<len; j++){
                if((i>>j)&1){
                  req.push_back(j);  
                } 
            }
            vector<int> degree(n,0);
            for(auto j:req){
                degree[r[j][0]]++;
                degree[r[j][1]]--;
            }
            for(auto j:degree) {
                if(j!=0) {
                    req.clear();
                    break;
                }
            }
            mx = max(mx,(int)req.size());
        }
        return mx;
    }
};