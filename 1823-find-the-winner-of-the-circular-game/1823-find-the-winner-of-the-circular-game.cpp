class Solution {
public:
    int solve(vector<int> &v, int index, int k){
        if(v.size() == 1){
            return v[0];
        }
        
        index = (index+k)%(v.size());
        v.erase(v.begin()+index);
        solve(v,index,k);
        
        return v[0];
    }
    
    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i = 1; i<=n; i++){
            v.push_back(i);
        }
        
        int x = k;
        x--;
        int index = 0;
        return solve(v,index,x);
    }
};