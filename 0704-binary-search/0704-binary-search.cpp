class Solution {
public:
    int search(vector<int>& num, int e) {
        int left = 0;
        int right = num.size()-1;
        
        while(left <= right){
            int mid = left + (right - left)/2;
            if(num[mid] == e){
                return mid;
            }
            else if(num[mid] < e){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }
};