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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* odd = head;
        ListNode* l1 = head->next;
        ListNode* even = l1;
        while(l1 != NULL && l1->next!=NULL){
            odd->next = l1->next;
            odd = odd->next;
            l1->next = odd->next;
            l1 = l1->next;
        }
        odd->next = even;
        return head;
    }
        
};