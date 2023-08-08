class Solution {
public:
    int lengthOfLastWord(string s) {
        // int ans = 0;
        int c = 0;
        for(int i = s.size()-1; i>=0 ; i--){
            if(s[i] != ' '){
                // break;
                c++;
            }
            else{
                // c++;
                // ans = max(ans,c);
                if(c > 0){
                    return c;
                }
            }
        }
        
        return c;
    }
};