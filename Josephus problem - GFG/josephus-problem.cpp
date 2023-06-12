//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    int solve(int k, int index, vector<int>&v){
        if(v.size() == 1){
            return v[0];
        }
        
        index = (index+k)%v.size();
        v.erase(v.begin()+index);
        
        solve(k,index,v);
        return v[0];
    }
    
    int josephus(int n, int k)
    {
       //Your code here
       vector<int> v;
       for(int i = 1; i<=n; i++){
           v.push_back(i);
       }
       
       int x = --k;
       int index = 0;
       return solve(k,index,v);
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends