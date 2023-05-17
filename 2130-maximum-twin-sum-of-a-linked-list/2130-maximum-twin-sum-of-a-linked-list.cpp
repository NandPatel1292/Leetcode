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
    int pairSum(ListNode* head) {
//         int ans = 0;
        
//         ListNode* slow = head;
//         ListNode* fast = head;
        
//         while(fast != NULL && fast->next != NULL){
//             fast = fast->next->next;
//             slow = slow->next;
//         }
        
//         ListNode* nx = NULL;
//         ListNode* prev = NULL;
        
//         while(slow != NULL){
//             nx = slow->next;
//             slow->next = prev;
//             prev = slow;
//             slow = nx;
//         }
        
//         ListNode* t1 = head;
//         ListNode* t2 = prev;
        
//         while(t2 != NULL){
//             ans = max(ans,t2->val + t1->val);
//             t1 = t1->next;
//             t2 = t2->next;
//         }
        
//         return ans;
        
        int ans = 0;
        vector<int> v;
        ListNode* tmp = head;
        
        while(tmp != NULL){
            v.push_back(tmp->val);
            tmp = tmp->next;
        }
        
        int n = 0;
        int m = v.size()-1;
        
        while(n <= m){
            ans = max(ans,v[n] + v[m]);
            n++;
            m--;
        }
        
        return ans;
    }
};