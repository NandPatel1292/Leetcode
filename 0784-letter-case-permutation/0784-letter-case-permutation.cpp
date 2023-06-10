class Solution {
public:
    void solve(string s, set<string>&ans, string op){
        if(s.size() == 0){
            ans.insert(op);
            return;
        }
        
        string op1 = op;
        string op2 = op;
        
        op1.push_back(tolower(s[0]));
        op2.push_back(toupper(s[0]));
        
        s.erase(s.begin());
        
        solve(s,ans,op1);
        solve(s,ans,op2);
    }
    
    
    vector<string> letterCasePermutation(string s) {
        vector<string> tmp;
        set<string>st;
        string op = "";
        solve(s,st,op);
        
        for(auto x : st){
            tmp.push_back(x);
        }
        return tmp;
    }
};