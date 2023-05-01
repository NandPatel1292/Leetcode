class Solution {
public:
    double average(vector<int>& s) {
        int mi = *min_element(s.begin(),s.end());
        int mx = *max_element(s.begin(),s.end());
        
        int sum = 0;
        for(auto i : s){
            sum += i;
        }
        
        setprecision(5);
        double ans = (sum - mi - mx)/(double)(s.size()-2);

        return ans;
    }
};