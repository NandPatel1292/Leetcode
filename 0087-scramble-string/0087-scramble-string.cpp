class Solution {
public:
    bool solve(string s1, string s2,unordered_map<string,bool>&mp){
        if(s1.compare(s2) == 0){
            return true;
        }
        if(s1.size()<=1){
            return false;
        }
        
        bool flg = false;
        int n = s1.size();
        string key = s1 + ' ' + s2;
        if(mp.find(key) != mp.end()){
            return mp[key];
        }
        
        for(int i = 1; i<n; i++){
            bool c1 = false;
            bool c2 = false;
            if(solve(s1.substr(0,i),s2.substr(n-i,i),mp) && solve(s1.substr(i,n-i),s2.substr(0,n-i),mp)){
                c1 = true;
            }
            if(solve(s1.substr(0,i),s2.substr(0,i),mp) && solve(s1.substr(i,n-i),s2.substr(i,n-i),mp)){
                c2 = true;
            }
            
            if(c1 || c2){
                flg = true;
            }
        }
        
        return mp[key] = flg;
    }
    
    
    bool isScramble(string s1, string s2) {
        // int n = s1.size();
        // vector dp(n+1,vector(n,vector<int>(n)));
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         dp[1][i][j] = (s1[i] == s2[j]);
        //     }
        // }
        // for(int k = 2; k<= n; k++){
        //     for(int i = 0; i<n+1 - k; i++){
        //         for(int j = 0; j< n+1 - k; j++){
        //             for(int nl = 1; nl < k; nl++){
        //                 const vector<int>& dp1 = dp[nl][i];
        //                 const vector<int>& dp2 = dp[k - nl][i+nl];
        //                 dp[k][i][j] |= dp1[j] && dp2[j+nl];
        //                 dp[k][i][j] |= dp1[j + k - nl] && dp2[j];
        //             }
        //         }
        //     }
        // }
        // return dp[n][0][0];
        
        unordered_map<string,bool>mp;
        if(s1.size()!= s2.size()){
            return false;
        }
        
        return solve(s1,s2,mp);
    }
};