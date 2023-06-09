class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char target) {
        if(target >= l[l.size()- 1]){
            return l[0];
        }
        else{
            int index = upper_bound(l.begin(),l.end(),target) - l.begin();
            // cout<<index;
            return l[index];    
        }
        
    }
};