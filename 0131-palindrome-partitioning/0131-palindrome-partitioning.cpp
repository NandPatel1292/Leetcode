class Solution {
public:
    
    bool isPali(string s,int ind,int i){
        while(ind <= i){
            if(s[ind++] != s[i--]){
                return false;
            }
        }
        return true;
    }
    
    void solve(int ind,string s,vector<string>&op,vector<vector<string>>&ans){
        if(ind == s.size()){
            ans.push_back(op);
            return;
        }
        
        for(int i = ind; i<s.size(); i++){
            if(isPali(s,ind,i)){
                op.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,op,ans);
                op.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>op;
        solve(0,s,op,ans);
        
        return ans;
    }
};