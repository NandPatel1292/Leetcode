class Solution {
public:
    int arraySign(vector<int>& n) {
        
        long long int ans = 1;
        
        for(auto i : n){
            if(i > 0){
                ans *= 1;
            }
            if(i < 0){
                ans *= -1;
            }
            if(i == 0){
                return 0;
            }
        }
        
        if(ans > 0){
            return 1;
        }
        else{
            return -1;
        }
        
    }
};