class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mx) {
        int n = mx.size();
        int m = mx[0].size();
        vector<int> ans;
        
        int left = 0;
        int right = m - 1;
        int top = 0;
        int bottom = n -1;
        
        while(top <= bottom && left <= right){
            
        
        
        for(int i = left; i<=right; i++){
            ans.push_back(mx[top][i]);
            
        }
        
        top++;
        
        for(int i = top; i<=bottom; i++){
            ans.push_back(mx[i][right]);
        }
        
        right--;
        
        if(top <= bottom){

        for(int i = right; i>= left; i--){
            ans.push_back(mx[bottom][i]);
        }
        
        bottom--;
            
        }
        
        if(left <= right){
            
        
        for(int i = bottom; i>= top; i--){
            ans.push_back(mx[i][left]);
        }
        
        left++;
        }    
    }
        return ans;
    }
    
};