//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>c, int a)
	{
	    int n = c.size();
        vector<vector<int>>dp(n+1,vector<int>(a+1));
        
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=a; j++){
                if(j == 0){
                    dp[i][j] = 0;
                }
                if(i == 0){
                    dp[i][j] = INT_MAX - 1;
                }
            }
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=a; j++){
                if(c[i-1] <= j){
                    dp[i][j] = min(dp[i][j-c[i-1]]+1,dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return (dp[n][a] == INT_MAX-1) ? -1 : dp[n][a];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends