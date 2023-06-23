//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solve(int i, int j, int ind, vector<vector<char>>&b, string w, int n, int m){
        if(ind == w.size()){
            return true;
        }
        
        if(i<0 || j<0 || i>= n || j>= m || b[i][j] != w[ind] || b[i][j] == '@'){
            return false;
        }
        
        char ch = b[i][j];
        b[i][j] = '@';
        
        bool top = solve(i-1,j,ind+1,b,w,n,m);
        bool right = solve(i,j+1,ind+1,b,w,n,m);
        bool bottom = solve(i+1,j,ind+1,b,w,n,m);
        bool left = solve(i,j-1,ind+1,b,w,n,m);
        
        b[i][j] = ch;
        
        return top || right || bottom || left;
    }

    bool isWordExist(vector<vector<char>>& b, string w) {
        // Code here
        int n = b.size();
        int m = b[0].size();
        int ind = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                
                if(b[i][j] == w[ind]){
                    if(solve(i,j,ind,b,w,n,m)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends