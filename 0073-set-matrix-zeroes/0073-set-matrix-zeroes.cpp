class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int c = m[0].size();
        int r = m.size();
        
        unordered_set<int>row;
        unordered_set<int>col;
        
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(m[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for(int i = 0; i<r;i++){
            for(int j = 0; j<c; j++){
                if(row.count(i) > 0 || col.count(j) > 0){
                    m[i][j] = 0;
                }
            }
        }
    }
};