class Solution {
public:
    bool get(vector<int>&p, int h,int mid){
        long long ans = 0;
        for(int i = 0; i<p.size(); i++){
            long long n = ceil(p[i]/(double)mid);
            ans += n;
        }
        return ans <= h;
    }
    int minEatingSpeed(vector<int>& p, int h) {
        int left = 1;
        int right = *max_element(p.begin(),p.end());
        while(left<=right){
            int mid = left + (right - left)/2;
            if(get(p,h,mid)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return right+1;
    }
};