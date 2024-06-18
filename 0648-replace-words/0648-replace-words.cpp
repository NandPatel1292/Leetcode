class Solution {
public:
    string solve(string i, unordered_set<string> d){
        for(int j = 1; j<=i.size(); j++){
            string x = i.substr(0,j);
            // if(find(d.begin(), d.end(), x) != d.end()){
            //     return x;
            // }
            if(d.contains(x)){
                return x;
            };
        }
        
        return i;
    }
    string replaceWords(vector<string>& d, string sen) {
        istringstream s(sen);
        string i;
        string ans;
        unordered_set<string> mp(d.begin(),d.end());
        
        while(s >> i){
           ans += solve(i,mp) + " "; 
        }
        
        ans.pop_back();
        
        return ans;
    }
};