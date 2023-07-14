//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int arr[],int i, int j,vector<vector<int>>&dp){
        if(i >= j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        // int mi = INT_MAX;
        dp[i][j] = INT_MAX;
        for(int k = i; k<=j-1; k++){
            dp[i][j] = min(dp[i][j],solve(arr,i,k,dp) + solve(arr,k+1,j,dp) + (arr[i-1]*arr[k]*arr[j]));
            // mi = min(mi,tmp);
        }
        
        return dp[i][j];
    }

    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int i = 1;
        int j = n-1;
        return solve(arr,i,j,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends