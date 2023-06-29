//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int w, int wt[], int val[], int n, vector<vector<int>>&dp){
        if(n == 0 ){
            // return 0;
            if(w >= wt[0]){
                return val[0];
            }
            else{
                return 0;
            }
        }
        
        if(dp[n][w] != -1){
            return dp[n][w];
        }
        
        int nottake = solve(w,wt,val,n-1,dp);
        
        int take = 0;
        if(wt[n] <= w){
            take = val[n]+solve(w - val[n],wt,val,n-1,dp);
        }
        
            
        dp[n][w] = max(take,nottake);
        
        return dp[n][w];
        
    }
    
    int func(int ind,int W,int wt[], int val[],vector<vector<int>>&dp ){
        if(ind==0){
            if(W>=wt[0]) return val[0];
            else return 0;
        }
        if(dp[ind][W]!=-1) return dp[ind][W];
        int dont=func(ind-1,W,wt,val,dp);
        int take=0;
        if(wt[ind]<=W){
            take=val[ind]+func(ind-1,W-wt[ind],wt,val,dp);
        }
        
        return dp[ind][W]=max(take,dont);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   vector<vector<int>>dp(n,vector<int>(w+1,-1));
       
    //   return solve(w,wt,val,n-1,dp);
    
    //  vector<vector<int>> dp(n,vector<int>(W+1,-1));
    //   return func(n-1,W,wt,val,dp);
    
     vector<vector<int>> dp(n+1,vector<int>(W+1));
     for(int i = 0; i<=n; i++){
         for(int j = 0; j<=W; j++){
             if(i == 0|| j ==0 ){
                 dp[i][j] = 0;
             }
             
             else if(wt[i-1] <= j){
                 dp[i][j] = max(val[i-1]+dp[i-1][j - wt[i-1]], dp[i-1][j]);
             }
             else{
                 dp[i][j] = dp[i-1][j];
             }
         }
     }
     
     return dp[n][W];
        
    
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends