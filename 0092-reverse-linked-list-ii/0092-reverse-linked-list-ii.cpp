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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
//         if(right == left){
//             return head;
//         }
//         ListNode* p = NULL;
//         ListNode* l = head;
//         if(left == 1){
//             p = head;
//         }
//         while(--left){
//             p = l;
//             l = l ->next;  
//         }
//         cout<<p->val<<" "<<l->val<<endl;
//         ListNode* r = head;
//         for(int i = 1; i<right; i++){
//             r = r -> next;
//         }
//         cout<<r->val<<" "<<r->next<<endl;\
//         ListNode* prev;
//         if(r->next == NULL){
//             prev = r;
//         }
//         else{
//             prev = r->next;
//         }
       
//         ListNode* curr = l;
//         ListNode* nt = NULL;
//         if(r->next != NULL){
            
//         while(curr != r){
//             nt = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nt;
//         }
//         }
        
//         p->next = curr;
//         curr->next = prev;
//         return head;
        
        stack<int>st;
        ListNode* tmp = head;
        ListNode* curr = head;
        
        for(int i = 0; i<left-1; i++){
            tmp = tmp->next;
        }
        curr = tmp;
        for(int i = 0; i<=right-left; i++){
            st.push(tmp->val);
            tmp = tmp->next;
        }
        
        for(int i = 0; i<=right-left; i++){
            curr->val = st.top();
            st.pop();
            curr = curr->next;
        }
        
        return head;
    }
};