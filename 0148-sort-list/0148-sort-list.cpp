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
    
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* tmp = NULL;        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        tmp->next = NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return margeList(l1,l2);
    }
    
    ListNode* margeList(ListNode* l1, ListNode* l2){
        ListNode* tmp = new ListNode(-1);
        ListNode* x = tmp;
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                x->next = l1;
                l1 = l1->next;
            }
            else {
                x->next = l2;
                l2 = l2->next;
            }
            x = x->next;
        }
        
        if(l1!=NULL){
            x->next = l1;
            l1 = l1->next;
            
        }
        if(l2 != NULL){
            x->next = l2;
            l2 = l2->next;
            
        }
        
        return tmp->next;
    }
};