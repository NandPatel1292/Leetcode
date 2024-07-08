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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* tmp = head->next;
        ListNode* pte = tmp;
        
        while(pte != NULL){
            int sum = 0;
            
            while(pte->val != 0){
                sum = sum + pte->val;
                pte = pte->next;
            }
            
            tmp->val = sum;
            pte = pte->next;
            tmp->next = pte;
            tmp = tmp->next;
        }
        
        return head->next;
    }
};