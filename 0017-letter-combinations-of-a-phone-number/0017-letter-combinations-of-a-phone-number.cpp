class Solution {
public:
    
    void solve(int ind,vector<string>ip,string op,vector<string>&ans){
        if(ind == ip.size()){
            ans.push_back(op);
            return;
        }
        
        for(int i = 0; i<ip[ind].size(); i++){
            op.push_back(ip[ind][i]);
            solve(ind+1,ip,op,ans);
            op.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string d) {
        vector<string> ans;
        if(d == ""){
            return ans;
        }
        unordered_map<char,string>mp;
        mp['0'] = "";
        mp['1'] = "";
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        vector<string>ip;
        for(int i = 0; i<d.size(); i++){
            ip.push_back(mp[d[i]]);
        }
        
        string op;
        solve(0,ip,op,ans);
        return ans;
    }
};