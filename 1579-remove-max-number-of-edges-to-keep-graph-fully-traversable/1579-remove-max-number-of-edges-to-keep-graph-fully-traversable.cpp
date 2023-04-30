class UnionFind{
    vector<int> rer;
    vector<int> com;
    
    int c;
    
public:
    UnionFind(int n){
        c = n;
        for(int i = 0; i<= n; i++){
            rer.push_back(i);
            com.push_back(1);
        }
    }
    
    int find(int n){
        if(rer[n] == n){
            return n;
        }
        
        return rer[n] = find(rer[n]);
    }
    
    int perform(int x, int y){
        x = find(x);
        y = find(y);
        
        if(x==y){
            return 0;
        }
        
        if(com[x] > com[y]){
            com[x] += com[y];
            rer[y] = x;
        }
        else{
            com[y] += com[x];
            rer[x] = y;
        }
        
        c--;
        return 1;
    }
    
    bool isConnect(){
        return c == 1;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
       UnionFind a(n), b(n);
        int edge = 0;
        
        for(vector<int>&x : edges){
            if(x[0] == 3){
                edge += (a.perform(x[1],x[2]) | b.perform(x[1],x[2]));
            }
        }
        
        for(vector<int>&x : edges){
            if(x[0] == 1){
                edge += a.perform(x[1],x[2]);
            }
            else if(x[0] == 2){
                edge += b.perform(x[1],x[2]);
            }
        }
        
        if(a.isConnect() && b.isConnect()){
            return edges.size() - edge;
        }
        
        return -1;
    }
};