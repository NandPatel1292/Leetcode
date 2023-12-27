class Solution {
public:
    int minCost(string c, vector<int>& t) {
        int req = 0;
     
        for(int i = 1; i<c.size(); i++){
           if(c[i] == c[i-1]){
               req += min(t[i],t[i-1]);
               t[i] = max(t[i],t[i-1]);
           }
        }
        
        return req;
    }
};