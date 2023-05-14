class Solution {
public:
    int backtrack(vector<int>&n, int mask, int pick, vector<int> &memo){
        if(2*pick == n.size()){
            return 0;
        }
        
        if(memo[mask] != -1){
            return memo[mask];
        }
        
        int ans = 0;
        
        for(int i = 0; i < n.size(); i++){
            for(int j = i+1; j<n.size(); j++){
                if(((mask >> i) & 1) == 1 or ((mask >> j) & 1) == 1){
                    continue;
                }
                
                int newMask = mask | (1 << i) | (1<< j);
                
                int curr = (pick + 1) * __gcd(n[i],n[j]);
                int rem = backtrack(n,newMask,pick+1,memo);
                
                ans = max(ans,curr+rem);
            }
        }
        
        memo[mask] = ans;
        return ans;
    }
    
    
    int maxScore(vector<int>& n) {
        int memoSize = 1 << n.size();
        vector<int> memo(memoSize,-1);
        return backtrack(n,0,0,memo);
    }
};