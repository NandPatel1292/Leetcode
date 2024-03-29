//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i = 0; i<n; i++){
	        sum += arr[i];
	    }
	    vector<vector<bool>>dp (n+1,vector<bool>(sum+1));
	    
	    for(int i = 0; i<=n; i++){
	        dp[i][0] = true;
	    }
	    for(int j = 1; j<=sum; j++){
	        dp[0][j] = false;
	    }
	    
	    for(int i = 1; i<=n; i++){
	        for(int j = 1; j<=sum; j++){
	            if(j >= arr[i-1]){
	                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	   // vector<int>v;
	    int mn = INT_MAX;
	    for(int i = sum/2; i>=0; i--){
	        if(dp[n][i] == true){
	            mn = sum - 2*i;
	            break;
	        }
	    }
	    
	    return mn;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends