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
    ListNode*findMidPrev(ListNode*head){

        ListNode*prev=nullptr;
        ListNode*slow=head;
        ListNode*fast=head;

        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        return prev;

    }
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(!head || !head->next) return nullptr;

        ListNode*midPrev=findMidPrev(head);

        ListNode*temp=midPrev->next;
        midPrev->next=midPrev->next->next;

        delete(temp);




        


        return head;
        
    }
};