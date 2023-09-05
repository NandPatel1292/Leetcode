/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* n = head;
    
//         while(n){
//             Node* tmp = n->next;
//             n->next = new Node(n->val);
//             n->next->next = tmp;
//             n = tmp;
//         }
        
//         n = head;
//         while(n){
//             if(n->random){
//                 n->next->random = n->random->next;
//             }
//             n = n->next->next;
//         }
        
//         Node* ans = new Node(0);
//         Node* res = ans;
        
//         while(head){
//             res->next = head->next;
//             res = res->next;
            
//             head->next = head->next->next;
//             head = head->next;
//         }
        
//         return ans->next;
        
        
        unordered_map<Node*, Node*>mp;
        while(n != NULL){
            mp[n] = new Node(n->val);
            n = n->next;
        }
        
        n = head;
        while(n != NULL){
            mp[n]->next = mp[n->next];
            mp[n]->random = mp[n->random];
            n = n->next;
        }
        
        return mp[head];
    }
};