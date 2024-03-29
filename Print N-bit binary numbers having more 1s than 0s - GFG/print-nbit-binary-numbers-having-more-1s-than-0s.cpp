//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    void solve(int n, string op, int one, int zero, vector<string>&ans){
        if( n == 0){
            ans.push_back(op);
            return;
        }
        
        string op1 = op;
        op1.push_back('1');
        solve(n-1,op1,one+1,zero,ans);
        
        if(one > zero){
            string op2 = op;
            op2.push_back('0');
            solve(n-1,op2,one,zero+1,ans);
        }
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> ans;
	    string op = "";
	    int one = 0;
	    int zero = 0;
	    
	    solve(n,op,one,zero,ans);
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends