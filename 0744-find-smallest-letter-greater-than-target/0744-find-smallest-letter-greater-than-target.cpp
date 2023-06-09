class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char target) {
        // if(target >= l[l.size()- 1]){
        //     return l[0];
        // }
        // else{
        //     int index = upper_bound(l.begin(),l.end(),target) - l.begin();
        //     // cout<<index;
        //     return l[index];    
        // }
        
        int left = 0;
        int right = l.size() - 1;
        int mid;
        while(left <= right){
            mid  =  left + (right - left)/2;
            if(l[mid] <= target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        
        return left == l.size() ? l[0] : l[right+1];
        
    }
};