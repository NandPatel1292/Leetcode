/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   struct compare
{
    bool operator()(
         struct ListNode* a, struct ListNode* b)
    {
        return a->val > b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& l) {
        int k = l.size();
        if( k == 0){
            return NULL;
        }
        priority_queue<ListNode* , vector<ListNode*>, compare> pq;
        
        for(int i = 0; i<k; i++){
            if(l[i] != NULL){
                pq.push(l[i]);
            }
        }
        if(pq.empty()){
            return NULL;
        }
        
        ListNode* tmp = new ListNode(-1);
        ListNode* last = tmp;
        
        while(!pq.empty()){
            ListNode* cur = pq.top();
            pq.pop();
            last->next = cur;
            last = last->next;
            
            if(cur->next != NULL){
                pq.push(cur->next);
            }
        }
        
        return tmp->next;
    }
};