class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        vector<string> s;
        int i = 0;
        for(auto x : t){
            while(i < x-1){
                s.push_back("Push");
                s.push_back("Pop");
                i++;
            }
            
        s.push_back("Push");
        i++;
        }
        return s;
    }
};