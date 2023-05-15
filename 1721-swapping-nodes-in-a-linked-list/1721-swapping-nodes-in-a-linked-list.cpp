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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* t1 = head;
        ListNode* t2 = head;
        
        for(int i = 0; i< k-1; i++){
            t2 = t2->next;
        }
        ListNode* tmp = t2;
        while(t2->next){
            t1 = t1->next;
            t2 = t2->next;
        }
        
        swap(t1->val,tmp->val);
        
        return head;
    }
};