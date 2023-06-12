class Solution {
public:
    vector<string> summaryRanges(vector<int>& n) {
        vector<string> ans;
        int f;
        int l;
        for(int i = 0; i<n.size(); i++){
            f = n[i];
            
            while(i < n.size()-1 && n[i+1] == n[i] + 1){
                i++;
            }            
            if(f != n[i]){
                ans.push_back(to_string(f)+"->"+to_string(n[i]));
            }
            else{
                ans.push_back(to_string(f));
            }
        }
        
        return ans;
    }
};