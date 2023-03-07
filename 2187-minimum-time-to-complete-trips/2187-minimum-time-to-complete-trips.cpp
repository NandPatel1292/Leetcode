class Solution {
public:
    bool timeTake(vector<int>&time,long long m,long long t){
        long long trp = 0;
        for(auto i:time){
            trp += m/i;
        }
        return trp >= t;
    }
    long long minimumTime(vector<int>& time, int t) {
        long long left = 1;
        long long right = 1ll * *max_element(time.begin(),time.end()) * t;
        
        while(left < right){
            long long mid = left + (right - left)/2;
            if(timeTake(time,mid,t)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};