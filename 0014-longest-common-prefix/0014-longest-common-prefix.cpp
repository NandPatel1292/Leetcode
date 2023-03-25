class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(),str.end());
        string s1 = str[0];
        string s2 = str[str.size()-1];
        string ans = "";        
        for(int i = 0; i<s1.size(); i++){
            if(s1[i] == s2[i]){
                ans += s1[i];
            }
            else{
                break;
            }
        }
        return ans;
        
    }
};