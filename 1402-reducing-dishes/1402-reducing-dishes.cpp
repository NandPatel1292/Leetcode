class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        
        int mx = 0;
        int sum = 0;
        
        for(int i = sat.size()-1; i>=0 && sum+sat[i] > 0; i--){
            sum += sat[i];
            mx += sum;
        }
        return mx;
    }
};