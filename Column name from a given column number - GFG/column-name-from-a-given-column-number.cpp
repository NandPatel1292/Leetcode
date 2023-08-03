//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string s;
        while(n > 0){
            long long int r = n%26;
            
            if(r == 0){
                s.insert(0,1,'Z');
                n = (n/26)-1;
            }
            else{
                char ch = (r-1)+'A';
                s.insert(0,1,ch);
                n = n/26;
            }
            
        }
        // string p = reverse(s.begin(), s.begin());
        // return reverse(s.begin(), s.end())
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends