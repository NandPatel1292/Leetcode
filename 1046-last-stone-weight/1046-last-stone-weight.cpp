class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int> pq;
        
        for(auto i : s){
            pq.push(i);
        }
        
        while(pq.size() >= 2){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            if(x != y){
                pq.push(abs(x - y));
            }
        }
        
        if(pq.size() == 0){
            return 0;
        }
        else{
            return pq.top();
        }
    }
};