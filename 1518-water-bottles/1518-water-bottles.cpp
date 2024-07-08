class Solution {
public:
    int numWaterBottles(int nb, int ne) {
        int ans = 0;
        while(nb >=ne){
            int rem = nb/ne;
            ans += ne*rem;
            nb -= ne*rem;
            
            nb += rem;
        }
        
        return ans+nb;
    }
};