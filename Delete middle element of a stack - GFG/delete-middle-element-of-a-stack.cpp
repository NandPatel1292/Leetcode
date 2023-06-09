//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    
    void solve(stack<int> &s, int k)
{
    if (k == 1)
    {
        s.pop();
        return;
    }
    int tmp = s.top();
    s.pop();

    solve(s, k - 1);
    s.push(tmp);
}

    void deleteMid(stack<int>&s, int sz)
    {
        if (sz == 0)
        {
            return;
        }
    else
        {
            int k = sz / 2 + 1;
            solve(s, k);
        } 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends