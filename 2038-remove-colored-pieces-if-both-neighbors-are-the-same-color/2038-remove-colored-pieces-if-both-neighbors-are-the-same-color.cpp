class Solution {
public:
    bool winnerOfGame(string c) {
        int a = 0;
        int b = 0;
        
        for(int i = 1; i<c.size()-1; i++){
            if(c[i] == c[i-1] && c[i] == c[i+1]){
                if(c[i] == 'A'){
                    a++;
                }
                else{
                    b++;
                }
            }
        }
        if(a > b){
            return true;
        }
        else{
            return false;
        }
    }
};