class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<int>ans;
        
        // for(int i = 0; i<min(n,m); i++){
        //     if(n > m){
        //         if(find(nums1.begin(),nums1.end(),nums2[i]) != nums1.end()){
        //             ans.push_back(nums2[i]);
        //             nums1.erase(nums1.begin()+i+1);
        //         }  
        //     }
        //     else{
        //         if(find(nums2.begin(),nums2.end(),nums1[i]) != nums2.end()){
        //             ans.push_back(nums1[i]);
        //             nums2.erase(nums2.begin()+i+1);
        //         }
        //     }
        // }
        
        map<int,int> mp;
        for(auto i : nums1){
            mp[i]++;
        }
        
        for(int i = 0; i<nums2.size(); i++){
            if(mp[nums2[i]] > 0){
                mp[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }
        
        
        
        return ans;
    }
};