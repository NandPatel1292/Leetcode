class Solution {
public:
    long long totalCost(vector<int>& c, int k, int cnd) {
        long long ans = 0;
        
        priority_queue<int,vector<int>, greater<int>>pq1,pq2;
        
        int cnt = 0;
        int l = 0;
        int r = c.size()-1;
        
        while(cnt<k){
            
            while(pq1.size()<cnd && l <= r){
                pq1.push(c[l++]);
            }
            
            while(pq2.size()<cnd && r >= l){
                pq2.push(c[r--]);
            }
            
            
            int c1;
            int c2;
            
            if(pq1.size() > 0){
                c1 = pq1.top();
            }
            else{
                c1 = INT_MAX;
            }
            
            if(pq2.size() > 0){
                c2 = pq2.top();
            }
            else{
                c2 = INT_MAX;
            }
            
            
            if(c1 <= c2){
                ans += c1;
                pq1.pop();
            }
            else{
                ans += c2;
                pq2.pop();
            }
            
            cnt++;
        }
        
        return ans;
    }
};