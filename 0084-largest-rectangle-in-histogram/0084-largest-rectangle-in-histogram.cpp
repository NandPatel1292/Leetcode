class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int>s;
        
        int ans = 0;
        h.push_back(0);
        for(int i = 0; i<h.size(); i++){
            while(!s.empty() && h[s.top()] > h[i]){
                int top = h[s.top()];
                s.pop();
                int tmp = s.empty() ? -1 : s.top();
                ans = max(ans,top*(i-tmp-1));
            }
            s.push(i);
        }
        return ans;
    }
};