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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(n==1 && !head->next) return NULL;

        //if(n==1) return head->next;

        ListNode*p1=head,*p2=head;

        for(int i=0;i<n;i++){
            p2=p2->next;
        }

        if(!p2) return head->next;

        while(p2->next){
            //prev=p1;
            p1=p1->next;
            p2=p2->next;
        }

        //if(prev==NULL){ return head->next;}

        ListNode*temp=p1->next;
        p1->next=p1->next->next;
        temp->next=NULL;

        return head;






    }
};