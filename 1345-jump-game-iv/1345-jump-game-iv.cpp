class Solution {
public:
    int minJumps(vector<int>& a) {
        int n = a.size();
        if(n==1){
            return 0;
        }
            //-23: [1, 2],
            //3: [8],
            //23: [5, 6, 7],
            //100: [0, 4],
            //404: [3, 9] 
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<n; i++){
            mp[a[i]].push_back(i);
        }
        
        queue<int> q;
        vector<bool>v(n);
        q.push(0);
        v[0] = true;
        int c = 0;
        
        while(!q.empty()){
            int x = q.size();
            while(x--){
                int cur = q.front();
                q.pop();
                
                if(cur == n-1){
                    return c;
                }
                vector<int>&jump = mp[a[cur]];
                jump.push_back(cur+1);
                jump.push_back(cur-1);
                for(int i:jump){
                    if(i>=0 && i<n && !v[i]){
                        q.push(i);
                        v[i] = true;
                    }
                }
                jump.clear();
            }
            c++;
        }
        return -1;
    }
};