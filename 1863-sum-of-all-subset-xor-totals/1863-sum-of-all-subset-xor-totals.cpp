class Solution {
public:
    
    int solve(vector<int>&n, int ind, int sum){
        if(ind == n.size()){
            return sum;
        }
        
        int s = solve(n, ind+1, sum ^ n[ind]);
        int sx = solve(n, ind+1, sum);
        
        return s + sx;
    }
    
    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
        
    }
};