class Solution {
public:
    int maxProfit(vector<int>& p) {
        int buy = INT_MAX;
        int profit = 0;
        for(int i = 0; i<p.size(); i++){
            buy = min(buy,p[i]);
            profit = max(profit,p[i]-buy);
        }
        
        return profit;
    }
};