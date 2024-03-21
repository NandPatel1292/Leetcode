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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* aStart = NULL;
        ListNode* bEnd = list1;
        
        for(int i = 0; i<b; i++){
            if(i == a-1){
                aStart = bEnd;
            }
            bEnd = bEnd->next;
        }
        
        aStart->next = list2;
        
        ListNode* end = list2;
        while(end->next != NULL){
            end = end->next;
        }
        
        end->next = bEnd->next;
        
        return list1;
    }
};