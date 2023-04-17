class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int mx = *max_element(candies.begin(),candies.end());
        // int mx = 0;
        // for(auto i : candies){
            // mx = max(mx,i);
        // }
        for(int i = 0; i<candies.size(); i++){
            if(candies[i]+ extraCandies >= mx){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};