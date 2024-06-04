class Solution {
public:
    int longestPalindrome(string s) {
       unordered_map<char,int>mp;
        for(auto i : s){
            mp[i]++;
        }
        
        int mx = 0;
        int c = 0;
        
        for(auto i : mp){
            if(i.second%2 == 0){
                c += i.second;
            }
            else{
                c += i.second - 1;
                mx = 1;
            }
        }
        
        return mx ? c + 1 : c;
    }
};