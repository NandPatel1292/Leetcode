class Solution {
public:
    void sortColors(vector<int>& n) {
        int l = 0;
        int h = n.size()-1;
        int mid = 0;
        
        while(mid <= h){
            if(n[mid] == 0){
                swap(n[l],n[mid]);
                l++;
                mid++;
                
            }
            
            else if(n[mid] == 1){
                mid++;
            }
            
            else if(n[mid] == 2){
                swap(n[h],n[mid]);
                h--;
            }
        }
    }
};