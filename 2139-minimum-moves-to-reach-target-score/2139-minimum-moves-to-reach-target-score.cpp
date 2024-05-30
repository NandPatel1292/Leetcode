class Solution {
public:
    int minMoves(int t, int d) {
        int c = 0;
        while(t >= 2 && d > 0){
            
           if(t % 2 == 0){
            if(d > 0){
                t /= 2;
                d--;
                c++;
            }
        }
        else{
            t--;
            c++;
        } 
            
            
        }
        
        return c + (t-1);
        
    }
};