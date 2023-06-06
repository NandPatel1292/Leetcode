class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // sort(arr.begin(),arr.end());
        int mi = *min_element(arr.begin(),arr.end());
        int mx = *max_element(arr.begin(),arr.end());
        int n = arr.size();
        
        if(mx - mi == 0){
            return true;
        }
        
        if((mx - mi)%(n-1) != 0){
            return false;
        }
        
        int dif = (mx - mi)/(n-1);
        unordered_set<int> s;
        // int dif = arr[1] - arr[0];
        for(int i = 0; i<n; i++){
            // if(arr[i+1] - arr[i] != dif){
            //     return false;
            // }
            
            if((arr[i] - mi)% dif != 0){
                return false;
            }
            s.insert(arr[i]);
        }
        
        return s.size() == n;
        
    }
};