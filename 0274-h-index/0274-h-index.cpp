class Solution {
public:
    int hIndex(vector<int>& arr) {
        int n = arr.size();
        
        // sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        for(auto i : arr){
            if(i >= n){
                mp[n]++;
            }
            else{
                mp[i]++;
            }
        }
        int ans = 0;
        for(int i = n; i>= 0; i--){
            ans += mp[i];
            if(ans >= i){
                return i;
            }
        }
        return 0;
        
        
    }
};