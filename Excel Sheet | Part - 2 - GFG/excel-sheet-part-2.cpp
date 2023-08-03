//{ Driver Code Starts
//Initial template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    int ExcelColumnNumber(string s)
    {
        // Your code goes here
        int c = 0;
        for(int i = 0; i<s.size(); i++){
            c += ((s[i]-'A'+1)*(pow(26,s.size()-1-i)));
        }
        
        return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.ExcelColumnNumber(s)<<endl;
    }
}
// } Driver Code Ends