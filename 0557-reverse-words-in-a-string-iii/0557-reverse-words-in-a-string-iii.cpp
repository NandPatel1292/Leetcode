class Solution {
public:
    string reverseWords(string s) {
        string r = "";
        string ans = "";
        int n = s.size();
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ' ' || i == n-1){
                if(i == n-1){
                    r += s[n-1];
                    reverse(r.begin(),r.end());
                    ans = ans+r;
                }
                else{
                    reverse(r.begin(),r.end());
                    ans = ans + r + " ";
                }
                r = "";
            }
            else{
                r += s[i];
            }
        }
        return ans;
    }
};