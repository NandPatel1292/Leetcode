class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        
        vector<int>mp1(26,0);
        vector<int>mp2(26,0);
        
        for(auto i : words[0]){
            mp1[i - 'a']++;
        }
        
        for(int i = 1; i<words.size(); i++){
            for(auto j : words[i]){
                mp2[j - 'a']++;
            }
            
            for(int k = 0; k<26; k++){
                mp1[k] = min(mp1[k], mp2[k]);
                mp2[k]=0;
            }
        }
        
        for(int i = 0; i<26; i++){
            if(mp1[i]>0){
                int c = mp1[i];
                while(c--){
                    char x = i + 'a';
                    string s;
                    s= x;
                    ans.push_back(s);
                }
            }
        }
        
        return ans;
    }
};