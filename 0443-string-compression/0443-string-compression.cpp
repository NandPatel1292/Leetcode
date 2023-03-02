class Solution {
public:
    int compress(vector<char>& n) {
        int q = n.size();
        if(q==1){
            return 1;
            
        }
        
        int i = 0;
        int j = 0;
        while(i < q){
            int c = 1;
            while(i < q-1 && n[i] == n[i+1]){
                c++;
                i++;
            }
            
            n[j] = n[i];
            j++;
            i++;
            if(c > 1){
                string s = to_string(c);
                for(auto x: s){
                    n[j] = x;
                    j++;
                }
            }
        }
        
        return j;
    }
};