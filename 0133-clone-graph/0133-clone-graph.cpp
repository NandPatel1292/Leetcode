/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* real,Node* copy, vector<Node*>&visit){
        visit[copy->val] = copy;
        for(auto x : real->neighbors){
            if(visit[x->val] == NULL){
                Node* newnode = new Node(x->val);
                (copy->neighbors).push_back(newnode);
                dfs(x,newnode,visit);
            }
            else{
                (copy->neighbors).push_back(visit[x->val]);
            }
        }
        
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        
        vector<Node*> visit(1000,NULL);
        Node* copy = new Node(node->val);
        visit[node->val] = copy;
        
        for(auto x : node->neighbors){
            if(visit[x->val] == NULL){
                Node* newnode = new Node(x->val);
                (copy->neighbors).push_back(newnode);
                dfs(x,newnode,visit);
            }
            else{
               ( copy->neighbors).push_back(visit[x->val]);
            }
        }
        
        return copy;
    }
};