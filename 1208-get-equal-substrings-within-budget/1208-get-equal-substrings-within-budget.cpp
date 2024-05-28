class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            int c = 0;
            int cost = abs(s[i]- t[i]);
            if(cost <= maxCost){
                c++;
            }
            else{
                continue;
            }
            for(int j = i+1; j<n; j++){
                cost += abs(s[j] - t[j]);
                if(cost <= maxCost){
                    c++;
                }
                else{
                    break;
                }
            }
            ans = max(ans,c);
        }
        
        return ans;
    }
};