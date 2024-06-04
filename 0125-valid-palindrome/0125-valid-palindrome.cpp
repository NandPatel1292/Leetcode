class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        
        while(l <= r){
            if(!iswalnum(s[l])){
                l++;
                continue;
            }
            if(!iswalnum(s[r])){
                r--;
                continue;
            }
            
            if(iswalnum(s[l]) && iswalnum(s[r])){
                if(tolower(s[l]) == tolower(s[r])){
                    l++;
                    r--;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};