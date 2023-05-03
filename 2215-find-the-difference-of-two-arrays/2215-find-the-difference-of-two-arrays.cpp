class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& num1, vector<int>& num2) {
        vector<vector<int>> ans(2, vector<int>());
        unordered_map<int, int> mp1, mp2;
        
        for(int i = 0; i < num1.size(); i++){
            mp1[num1[i]]++;
        }
        for(int i = 0; i < num2.size(); i++){
            mp2[num2[i]]++;
        }
        
        for(auto x : mp1){
            if(mp2.find(x.first) == mp2.end()){
                ans[0].push_back(x.first);
            }
        }
        for(auto x : mp2){
            if(mp1.find(x.first) == mp1.end()){
                ans[1].push_back(x.first);
            }
        }
        
        return ans;
    }
};
