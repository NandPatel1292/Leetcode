class Solution {
public:
    int numberOfSubarrays(vector<int>& n, int k) {
        map<int,int> mp;
        int sum = 0;
        mp[0] = 1;
        int c = 0;
        for(int i = 0; i<n.size(); i++){
            if(n[i]%2==0){
                n[i] = 0;
                
            }
            else{
                n[i] = 1;
            }
        }
        for(int i = 0; i<n.size(); i++){
            sum += n[i];
            
            if(mp.find(sum - k) != mp.end()){
                c+= mp[sum - k];
            }
            mp[sum]++;
        }
        return c;
    }
};