class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        vector<int> f(n,0);
        vector<int> h(n,0);
        
        h[0] = -p[0];
        
        for(int i = 1; i<n; i++){
            f[i] = max(f[i-1],h[i-1]+p[i]-fee);
            h[i] = max(h[i-1],f[i-1]-p[i]);
        }
        
        return f[n-1];
    }
};