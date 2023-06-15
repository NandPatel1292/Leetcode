//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string solve(string s, int start, int end){
        string r;
        for(int i = start; i<=end; i++){
            r.push_back(s[i]);
        }
        
        return r;
    }
    
    string longestPalin (string s) {
        // code here
        int l;
        int h;
        int start = 0; 
        int end = 1;
        for(int i = 1; i<s.size(); i++){
            l = i - 1;
            h = i;
            
            while(l>=0 && h<s.size() && s[l] == s[h]){
                if(h-l+1>end){
                    start = l;
                    end = h-l+1;
                    
                }
                
                l--;
                h++;
            }
            
            l = i - 1;
            h = i+1;
            
            while(l>=0 && h<s.size() && s[l] == s[h]){
                if(h-l+1>end){
                    start = l;
                    end = h-l+1;
                    
                }
                
                l--;
                h++;
            }
        }
        
        return solve(s,start,start+end-1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends