class Solution {
public:
    
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int x=row;
        int y=col;
        
        while(y>=0)
        {
            if(board[x][y]=='Q')
            {
                return false;
            }
            y--;
        }
        
        x=row;
        y=col;
        
        while(x>=0 && y>=0)
        {
            if(board[x][y]=='Q')
            {
                return false;
            }
            x--;
            y--;
        }
        
        x=row;
        y=col;
        
        while(x<n && y>=0)
        {
            if(board[x][y]=='Q')
            {
                return false;
            }
            x++;
            y--;
        }
        
        return true;
    }

    void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(row, col, board, n))
            {
                board[row][col]='Q';
                solve(col+1, ans, board, n);
                board[row][col]='.';
            }
        }
    }
    
    void solve2(int col, vector<vector<string>>&ans,vector<string>&p,int n,vector<int>&left,vector<int>&uppr,vector<int>&lower){
        if(col == n){
            ans.push_back(p);
            return;
        }
        
        for(int i = 0; i<n; i++){
            if(left[i] == 0 && lower[i+col] == 0 && uppr[n-1+col-i] == 0){
                p[i][col] = 'Q';
                left[i] = 1;
                uppr[n-1 + col - i] = 1;
                lower[i+col] = 1;
                solve2(col+1,ans,p,n,left,uppr,lower);
                p[i][col] = '.';
                left[i] = 0;
                uppr[n-1+col-i] = 0;
                lower[i+col] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n,'.');
        vector<string>p(n,s);
        
        
        // solve(0,ans,p,n);
        
        vector<int>left(n,0);
        vector<int> uppr(2*n-1,0);
        vector<int>lower(2*n-1,0);
        solve2(0,ans,p,n,left,uppr,lower);
        return ans;
    }
};