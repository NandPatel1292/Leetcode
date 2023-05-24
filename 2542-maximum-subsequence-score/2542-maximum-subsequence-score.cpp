class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>> pq;
        
        for(int i = 0; i<nums1.size(); i++){
            pq.push({nums2[i],nums1[i]});
        }
        
        
        long long res = 0;
        long long sum = 0;
        int mi = 1000000;
        vector<int> ans1,ans2;
        while(!pq.empty()){
            ans1.push_back(pq.top().second);
            ans2.push_back(pq.top().first);
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            pq.pop();
        }
        
        priority_queue<int,vector<int>, greater<int>> tp;
        for(int i = 0; i<k-1; i++){
            tp.push(ans1[i]);
            sum += ans1[i];
        }
        
        for(int i = k-1; i<nums1.size(); i++){
            res = max(res,ans2[i]*(sum + ans1[i]));
            
            tp.push(ans1[i]);
            sum += ans1[i];
            
            if(tp.size() == k){
                sum -= (tp.top());
                tp.pop();
            }
        }
        return res;
    }
};