//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void ins(stack<int> &s, int tmp){
    if(s.size() == 0 || s.top() <= tmp){
        s.push(tmp);
        return;
    }
    
    int val = s.top();
    s.pop();
    ins(s,tmp);
    s.push(val);
}

void st(stack<int>&s){
    if(s.size() == 1){
       return;
   }
   int tmp = s.top();
   s.pop();
   st(s);
   ins(s,tmp);
}
void SortedStack :: sort()
{
   //Your code here
   st(s);
}