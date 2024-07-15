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

    ListNode*reverse(ListNode*&head){
        ListNode*prev=NULL,*curr=head;
        while(curr){
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            
            curr=temp;

        }

        return prev;
    }


    ListNode*findMid(ListNode*&head){
        ListNode*slow=head,*fast=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

    bool isPalindrome(ListNode* head) {

        if(!head->next) return true;


        ListNode*mid=findMid(head);

        ListNode*head2=reverse(mid->next);

        ListNode*curr1=head,*curr2=head2;

        while(curr2){
            if(curr2->val != curr1->val){reverse(head2); return false;}

            curr1=curr1->next;
            curr2=curr2->next;
        }

        return true;

        
        
    }
};