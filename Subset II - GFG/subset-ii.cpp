//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    void solve(vector<int>n, vector<int>op, set<vector<int>>&s){
        if(n.size() == 0){
            sort(op.begin(),op.end());
            s.insert(op);
            return;
        }
        
        int x = n[n.size()-1];
        n.pop_back();
        solve(n,op,s);
        op.push_back(x);
        solve(n,op,s);
    }
  
    vector<vector<int>> printUniqueSubsets(vector<int>& n) {
        // Write your code here
        vector<vector<int>>ans;
        set<vector<int>>s;
        vector<int>op;
        solve(n,op,s);
        
        for(auto i : s){
            ans.push_back(i);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends