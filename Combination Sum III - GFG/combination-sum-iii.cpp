//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void solve(int ind,vector<int>op, vector<int>ip, vector<vector<int>>&ans, int n, int k){
        if(ind == ip.size()){
            if(n == 0 && k == 0){
                ans.push_back(op);
                return;
            }
            
            return;
        }
        
        if(ip[ind] <= n){
            op.push_back(ip[ind]);
            solve(ind+1,op,ip,ans,n-ip[ind],k-1);
            op.pop_back();
        }
        
        solve(ind+1,op,ip,ans,n,k);
    }
  
    vector<vector<int>> combinationSum(int k, int n) {
        // code here
        vector<int>ip;
        for(int i = 1; i<10; i++){
            ip.push_back(i);
        }
        
        vector<int>op;
        vector<vector<int>>ans;
        
        solve(0,op,ip,ans,n,k);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends