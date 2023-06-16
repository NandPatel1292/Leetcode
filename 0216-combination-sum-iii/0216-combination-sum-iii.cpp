class Solution {
public:
    
    void solve(int ind, vector<int>op, vector<int>ip, vector<vector<int>>&ans,int k, int n){
        if(ind == ip.size()){
            if(k == 0 && n == 0){
                ans.push_back(op);
            }
            return;
        }
        
        if(ip[ind] <= n){
            op.push_back(ip[ind]);
            solve(ind+1,op,ip,ans,k-1,n-ip[ind]);
            while(ind < ip.size()-1 && ip[ind] == ip[ind+1]){
                ind++;
            }
            op.pop_back();
        }
        
        solve(ind+1,op,ip,ans,k,n);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ip;
        for(int i = 1; i<10; i++){
            ip.push_back(i);
            
        }
        
        vector<vector<int>>ans;
        vector<int> op;
        solve(0,op,ip,ans,k,n);
        
        return ans;
    }
};