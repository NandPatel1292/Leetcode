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
    
    bool exist(vector<vector<char>>& b, string w) {
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