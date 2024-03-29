//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int index, int arr[], int n, int tar, vector<vector<int>>&dp){
        if(index >= n){
            return 0;
        }
        if(tar < 0){
            return 0;
        }
        
        if(tar == 0){
            return 1;
        }
        
        if(dp[index][tar] != -1){
            return dp[index][tar];
        }
        
        bool inc = solve(index+1, arr,n,tar - arr[index],dp);
        bool exe = solve(index+1,arr,n,tar,dp);
        
        
        return dp[index][tar] = exe or inc;
    }

    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        
        if(sum%2 != 0){
            return 0;  
        }
        
        int tar = sum/2;
        
        // vector<vector<int>> dp(n,vector<int>(tar+1,-1));
        // return solve(0,arr,n,tar,dp);
        
        vector<vector<int>>dp(n+1,vector<int>(tar+1));
        for(int i = 0; i<=n; i++){
            dp[i][0] = true;
        }
        for(int j = 1; j<= tar; j++){
            dp[0][j] = false;
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=tar; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][tar];
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends