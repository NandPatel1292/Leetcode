//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(int i, int j,vector<vector<int>>&m, vector<string>&ans, vector<vector<int>>&visit, string op, int n){
        if(i == n-1 && j== n-1){
            ans.push_back(op);
            return;
        }
        
        // for down
        if(i<n-1 && visit[i+1][j] == 0 && m[i+1][j] == 1){
            visit[i][j] = 1;
            solve(i+1,j,m,ans,visit,op+'D',n);
            visit[i][j] = 0;
        }
        
        // for left
        if(j-1>=0 && visit[i][j-1] == 0 && m[i][j-1] == 1){
            visit[i][j] = 1;
            solve(i,j-1,m,ans,visit,op+'L',n);
            visit[i][j] = 0;
        }
        
        // for Right
        if(j<n-1 && visit[i][j+1] == 0 && m[i][j+1] == 1){
            visit[i][j] = 1;
            solve(i,j+1,m,ans,visit,op+'R',n);
            visit[i][j] = 0;
        }
        
        // for Up
        if(i-1>=0 && visit[i-1][j] == 0 && m[i-1][j] == 1){
            visit[i][j] = 1;
            solve(i-1,j,m,ans,visit,op+'U',n);
            visit[i][j] = 0;
        }
    }
    
    void solve2(int i, int j,vector<vector<int>>&m, vector<string>&ans, vector<vector<int>>&visit, string op, int n,vector<int>di,vector<int>dj){
        if(i == n-1 && j == n-1){
            ans.push_back(op);
            return;
        }
        
        string dir = "DLRU";
        for(int k = 0; k<4; k++){
            int ni = i + di[k];
            int nj = j + dj[k];
            
            if(ni >=0 && nj>=0 && ni<n && nj <n && visit[ni][nj] == 0 && m[ni][nj] == 1){
                visit[i][j] = 1;
                solve2(ni,nj,m,ans,visit,op+dir[k],n,di,dj);
                visit[i][j] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>>visit(n,vector<int>(n,0));
        string op = "";
        // if(m[0][0] == 1){
        //     solve(0,0,m,ans,visit,op,n);
        // }
        
        vector<int>di = {1,0,0,-1};
        vector<int>dj = {0,-1,1,0};
        if(m[0][0] == 1){
            solve2(0,0,m,ans,visit,op,n,di,dj);
        }
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends