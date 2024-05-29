class Solution {
public:
    int numSteps(string s) {
        int c = 0;
        
        while(s.size() > 1){
            int n = s.size();
            if(s[n-1] == '0'){
                s.pop_back();
            }
            else{
                int m = s.size()-1;
                
                while(m>=0 && s[m] != '0'){
                    s[m] = '0';
                    m--;
                }
                
                if(m < 0){
                    s = '1' + s;
                    
                }
                else{
                    s[m] = '1';
                }
            }
            c++;
        }
        
        return c;
    }
};