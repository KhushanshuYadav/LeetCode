/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(!head ||!head->next ) return NULL;

        ListNode*slow=head,*fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) break;
        }

        if(fast!=slow) return NULL;

        
        fast=head;

        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;

        }

        return fast;
    }
};