//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        if(n < 3){
            return false;
        }
        sort(arr,arr+n);
        
        if(arr[0] > 0){
            return false;
        }
        
       
        for(int i = 0; i<n; i++){
             int l = i+1; 
            int h = n-1;
            int sum = 0;
            if(arr[i] > 0){
                break;
            }
            
            if(i > 0 && arr[i] == arr[i-1]){
                continue;
            }
            
            while(l < h){
                sum = arr[i] + arr[l] + arr[h];
                if(sum > 0){
                    h--;
                }
                else if(sum < 0){
                    l++;
                }
                else{
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends