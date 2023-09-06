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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        
        int len = 0;
        ListNode* tmp = head;
        while(tmp){
            len++;
            tmp = tmp->next;
        }
        
        int n = len/k;
        int r = len%k;
        
        int i = 0;
        tmp = head;
        while(tmp){
            ans.push_back(tmp);
            int cur = 1;
            while(cur < n){
                tmp = tmp->next;
                cur++;
            }
            if(r>0 && len>k){
                tmp = tmp->next;
                r--;
            }
            ListNode* x = tmp->next;
            tmp->next = NULL;
            tmp = x;
            
        }
        while(len < k){
            ans.push_back(NULL);
            len++;
        }
        return ans;
        
    }
};