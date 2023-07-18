//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    bool solve(string s1, string s2, unordered_map<string,bool>&mp){
        if(s1.compare(s2) == 0){
            return true;
        }
        if(s1.size() <= 1){
            return false;
        }
        
        int n = s1.size();
        bool f = false;
        string key = s1 + ' ' + s2;
        if(mp.find(key) != mp.end()){
            return mp[key];
        }
        
        for(int i = 1; i<n; i++){
            bool c1 = false;
            bool c2 = false;
            
            if(solve(s1.substr(0,i),s2.substr(n-i,i),mp) && solve(s1.substr(i,n-i),s2.substr(0,n-i),mp)){
                c1 = true;
            }
            if(solve(s1.substr(0,i),s2.substr(0,i),mp) && solve(s1.substr(i,n-i),s2.substr(i,n-i),mp)){
                c2 = true;
            }
            
            if(c1 || c2){
                f = true;
            }
        }
        
        return mp[key] = f;
    }
    
    bool isScramble(string S1, string S2){
        //code here
        unordered_map<string,bool>mp;
        if(S1.size() != S2.size()){
            return false;
        }
        return solve(S1,S2,mp);
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends