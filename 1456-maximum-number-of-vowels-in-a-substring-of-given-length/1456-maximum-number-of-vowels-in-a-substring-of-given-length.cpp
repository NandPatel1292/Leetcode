class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int count = 0;
        // int mx = 0;
        for (int i = 0, local = 0; i < s.size(); i++) {
            local += vowels.count(s[i]);
            if (i - k >= 0) local -= vowels.count(s[i-k]);
            count = max(count, local);
        }
        return count;
        // if(mx > k){
        //     return k;
        // }
        // else{
        //     return mx;
        // }
        
        // return min(mx,k);
        
        
    }
};