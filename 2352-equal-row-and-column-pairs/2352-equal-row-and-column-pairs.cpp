class Solution {
public:
    int equalPairs(vector<vector<int>>& g) {
        int c = 0;
        int n = g.size();
        
//         for(int i = 0; i<n; i++){
//             for(int j = 0; j<n; j++){
//                 int f = 1;
//                 for(int k = 0; k<n; k++){
//                     if(g[i][k] != g[k][j]){
//                         f = 0;
//                         break;
//                     }
//                 }
//                 if(f){
//                     c++;
//                 }
              
//             }
//         }
        
        
        unordered_map<string,int> mp;
        for(int i = 0; i<n; i++){
            string ans = "";
            
            for(int j = 0; j<n; j++){
                ans += to_string(g[i][j]) + "N";
            }
            mp[ans]++;
        }
        
        for(int i = 0; i<n; i++){
                string chk = "";
            for(int j = 0; j<n; j++){
                chk += to_string(g[j][i]) + "N";
            }
            if(mp.find(chk) != mp.end()){
                c = c + mp[chk];
            }
        }
        
        return c;
    }
};