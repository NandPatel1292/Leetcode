class Solution {
public:
    int strStr(string h, string n) {
        int a = h.size();
        int b = n.size();
        for(int i = 0; i<= a - b; i++){
            for(int j=0; j<b; j++){
                if(n[j] != h[j+i]){
                    break;
                }
                if(j == b-1){
                    return i;
                }
            }
        }
        return -1;
    }
};

