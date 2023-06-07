class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for(int i = 0; i<32; i++){
            int a1 = a >> i;
            int b1 = b >> i;
            int c1 = c >> i;
            
            if((c1&1) == 1){
                if((a1&1) == 0 && (b1&1) == 0){
                    res++;
                }
            }
            else{
                res += (a1&1) + (b1&1);
            }
            
        }
        
        return res;
    }
};