class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        int s = hand.size();
        
        if(s % g != 0){
            return false;
        }
        
        map<int,int>c;
        for(int i = 0; i<s; i++){
            c[hand[i]]++;
        }
        
        while(!c.empty()){
            int curr = c.begin()->first;
            
            for(int i = 0; i<g; i++){
                if(c[curr+i] == 0){
                    return false;
                }
                c[curr+i]--;
                if(c[curr+i] < 1){
                    c.erase(curr+i);
                }
            }
        }
        
        return true;
    }
};