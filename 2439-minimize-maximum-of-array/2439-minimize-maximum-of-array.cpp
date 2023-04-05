class Solution {
public:
    int minimizeArrayValue(vector<int>& n) {
        int ans = 0;
        long long sum = 0;
        
        for(int i = 0; i< n.size(); i++){
            sum += n[i];
            int tmp = ceil(double(sum)/(i+1));
            ans = max(ans,tmp);
        }
        return ans;
    }
};