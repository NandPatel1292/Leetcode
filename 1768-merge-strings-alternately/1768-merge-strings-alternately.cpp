class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string ans = "";
        for(int i = 0; i<max(w1.size(),w2.size()); i++){
            if(i < w1.size()){
                ans.push_back(w1[i]);
            }
            if(i < w2.size()){
                ans.push_back(w2[i]);
            }
        }
        
        return ans;
    }
};