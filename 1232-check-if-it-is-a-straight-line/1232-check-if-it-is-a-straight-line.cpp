class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int n = c.size();
        
        if(n <= 2){
            return true;
        }
          
        for(int i = 2; i<n; i++){
            if((c[i][0] - c[0][0])*(c[1][1] - c[0][1]) != (c[i][1] - c[0][1])*(c[1][0] - c[0][0])){
                return false;
            }
        }
        
        return true;
    }
};