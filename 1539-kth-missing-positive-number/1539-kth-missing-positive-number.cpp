class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if((arr[mid] - mid - 1) >= k){
                right = mid-1;
            }
            else{
                left = mid + 1;
            }
        }
        return right+k+1;
        // return left+k;
    }
};