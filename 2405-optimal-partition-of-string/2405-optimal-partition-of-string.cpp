class Solution {
public:
    int partitionString(string s) {
        int c = 0;
        map<char,int> mp;

        for(int i = 0; i<s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                mp.clear();
                c++;
            }
            mp[s[i]]++;
        }
       
        return c+1;
    }
};