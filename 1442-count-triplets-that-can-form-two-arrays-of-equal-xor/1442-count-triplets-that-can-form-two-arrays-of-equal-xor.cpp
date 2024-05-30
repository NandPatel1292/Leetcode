class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int c = 0;
        int s = arr.size();
        vector<int>pre(s);       
        pre[0] = arr[0];
        for(int i = 1; i<arr.size(); i++){
            pre[i] = pre[i-1] ^ arr[i];
        }
        
        pre.insert(pre.begin(),0);
       
        for(int i = 0; i<pre.size(); i++){
            for(int j = i+1; j<pre.size(); j++){
                if(pre[i] == pre[j]){
                    c += (j - i - 1);
                }
            }
        }
        // cout<<endl;
        
        return c;
    }
};