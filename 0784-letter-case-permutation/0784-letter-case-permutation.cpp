class Solution {
public:
    void solve(string s, vector<string>&ans, string op){
        if(s.size() == 0){
            ans.push_back(op);
            return;
        }
        
       
        
        if(isalpha(s[0])){
            string op1 = op;
            string op2 = op;
            
            op1.push_back(tolower(s[0]));
            op2.push_back(toupper(s[0]));
            
            s.erase(s.begin());
            
            solve(s,ans,op1);
            solve(s,ans,op2);
        }
        else{
            string op1 = op;
            op1.push_back(s[0]);
            s.erase(s.begin());
            solve(s,ans,op1);
        }
        
        
        
        
        
        
    }
    
    
    vector<string> letterCasePermutation(string s) {
        vector<string> tmp;
        string op = "";
        
        solve(s,tmp,op);
        
        return tmp;
    }
};