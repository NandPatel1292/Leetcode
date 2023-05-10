class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int c = 1;
        int right = n-1, left = 0;
        int top = 0, bottom = n - 1;
        vector<vector<int>> ans(n,vector<int>(n));
        while(top <= bottom && left <= right){
            for(int i = left; i<= right; i++){
                ans[top][i] = c;
                c++;
            }
            
            top++;
            
            for(int i = top; i<= bottom; i++){
                ans[i][right] = c;
                c++;
            }
            
            right--;
            
            if(top <= bottom){
                for(int i = right; i>= left; i--){
                    ans[bottom][i] = c;
                    c++;
                }
                bottom--;
            }
            
            if(left <= right){
                for(int i = bottom; i>= top; i--){
                    ans[i][left] = c;
                    c++;
                }
                left++;
            }
        }
        
        return ans;
    }
};