class Solution {
public:
    int findDuplicate(vector<int>& n) {
        int ans;
//         unordered_map<int,int>mp;
//         for(int i = 0; i<nums.size(); i++){
//             mp[nums[i]]++;
//         }
        
//         for(auto i : mp){
//             if(i.second >= 2){
//                 ans = i.first;
//             }
//         }
//         return ans;
        
        sort(n.begin(),n.end());
        for(int i = 0; i<n.size()-1; i++){
            if(n[i] == n[i+1]){
                ans = n[i];
                break;
            }
        }
        return ans;
    }
};