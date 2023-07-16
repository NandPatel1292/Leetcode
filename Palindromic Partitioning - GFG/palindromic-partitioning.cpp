//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool ispali(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string& s, int i, int j, vector<vector<int>>&dp){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(i >= j){
            return dp[i][j] =  0;
        }
        if(ispali(s,i,j)){
            return dp[i][j] = 0;
        }
        
        int tmp = INT_MAX;
        for(int k = i; k<j; k++){
            if(ispali(s,i,k) == false){
                continue;
            }
            
//             int left;
//             int right;
            
//             if(dp[i][k] != -1){
//                 left = dp[i][k];
//             }
//             else{
//                 left = solve(s,i,k,dp);
//                 dp[i][k] = left;
//             }
//             if(dp[k+1][j] != -1){
//                 right = dp[k+1][j];
//             }
//             else{
//                 right = solve(s,k+1,j,dp);
//                 dp[k+1][j] = right;
//             }
            int ans = 1 + solve(s,i,k,dp) + solve(s,k+1,j,dp);
            tmp = min(tmp, ans);
            // tmp = min(tmp, 1 + right + left);
        }
        return dp[i][j] = tmp;
    }

    int palindromicPartition(string s)
    {
        // code here
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends