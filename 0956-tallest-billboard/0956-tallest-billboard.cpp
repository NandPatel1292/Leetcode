class Solution {
public:
    map<pair<int,int>,int>mp;
    int solve(int ind, int dif, vector<int>&r){
        if(ind == r.size()){
            if(dif == 0){
                return 0;
            }
            return -1e5;
        }
        
        if(mp.count({ind,dif})){
            return mp[{ind,dif}];
        }
        
        int op1 = r[ind] + solve(ind+1,dif+r[ind],r);
        int op2 = solve(ind+1,dif - r[ind],r);
        int op3 = solve(ind+1,dif,r);
        
        return mp[{ind,dif}] = max({op1,op2,op3});
    }
    
    int tallestBillboard(vector<int>& rods) {
        return solve(0,0,rods);
    }
};