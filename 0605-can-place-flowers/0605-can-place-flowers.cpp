class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int c = 0;
        
        for(int i = 0; i<f.size(); i++){
            if(f[i] == 0){
                bool left = (i == 0) || (f[i-1] == 0);
                bool right = (i == f.size()-1) || (f[i+1] == 0);
                
                if(left && right){
                f[i] = 1;
                c++;
                if(c >= n){
                    return true;
                }
            }
                
            }
            
            
        }
        return c >= n;
    }
};