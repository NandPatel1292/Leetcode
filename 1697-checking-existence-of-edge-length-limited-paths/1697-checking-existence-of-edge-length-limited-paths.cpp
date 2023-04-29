class UnionFind{
public:
    vector<int> group;
    vector<int> rank;
    
    UnionFind(int s){
        group = vector<int>(s);
        rank = vector<int>(s);
        for(int i = 0; i<s; i++){
            group[i] = i;
        }
    }
    
    int find(int node){
        if(group[node] != node){
            group[node] = find(group[node]);
        }
        return group[node];
    }
    
    void join(int node1, int node2){
        int g1 = find(node1);
        int g2 = find(node2);
        
        if(g1 == g2){
            return;
        }
        
        if(rank[g1] > rank[g2]){
            group[g2] = g1;
        }
        else if(rank[g2] > rank[g1]){
            group[g1] = g2;
        }
        else{
            group[g1] = g2;
            rank[g2] += 1;
        }
     }
    
    bool isConnect(int node1, int node2){
        int g1 = find(node1);
        int g2 = find(node2);
        return g1 == g2;
    }
    
    
};



class Solution {
public:
    
    bool static comp(vector<int>&a, vector<int>&b){
        return a[2] < b[2];
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        UnionFind uf(n);
        int qc = queries.size();
        vector<bool> ans(qc);
        
        vector<vector<int>> qindex(qc);
        for(int i = 0; i<qc; i++){
            qindex[i] = queries[i];
            qindex[i].push_back(i);
        }
        
        int eindex = 0;
        
        sort(edgeList.begin(),edgeList.end(),comp);
        sort(qindex.begin(),qindex.end(),comp);
        
        for(auto & x : qindex){
            int p = x[0];
            int q = x[1];
            int limit = x[2];
            int qOriginalIndex = x[3];
            
            
            while(eindex < edgeList.size() && edgeList[eindex][2] < limit){
                int node1 = edgeList[eindex][0];
                int node2 = edgeList[eindex][1];
                uf.join(node1,node2);
                eindex++;
            }
            
            ans[qOriginalIndex] = uf.isConnect(p,q);
        }
        
        return ans;
    }
};