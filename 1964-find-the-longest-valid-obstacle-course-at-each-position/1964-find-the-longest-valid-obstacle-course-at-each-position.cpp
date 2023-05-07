class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& ob) {
        vector<int>ans;
        vector<int> v(ob.size(),(int)1e9);
        for(auto x : ob){
            auto i = upper_bound(v.begin(),v.end(),x);
            ans.emplace_back(i - v.begin()+1);
            *i = x;
        }
        return ans;
    }
};