class Solution {
public:
    void nextPermutation(vector<int>& n) {
        int s = n.size();
        int i,j;
        for(i = s-2;i>=0; i--){
            if(n[i+1]>n[i]){
                break;
            }
        }
        
        if(i < 0){
            reverse(n.begin(),n.end());
        }
        else{
            
        
        
        for(j = s-1; j>i; j--){
            if(n[j] > n[i]){
                break;
            }
        }
        
        swap(n[i],n[j]);
        
        reverse(n.begin()+i+1,n.end());
        
        }
    }
};