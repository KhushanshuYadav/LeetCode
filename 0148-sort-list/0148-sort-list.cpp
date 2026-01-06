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

    ListNode*merge(ListNode*a,ListNode*b){

        if(!a) return a;
        if(!b) return b;

        ListNode*head=nullptr;
        ListNode*tail=nullptr;

        if(a->val<=b->val){
            head=tail=a;
            a=a->next;
        }
        else{
            head=tail=b;
            b=b->next;
        }

        while(a && b){
            if(a->val<=b->val){
                tail->next=a;
                tail=a;
                a=a->next;
            }
            else{
                tail->next=b;
                tail=b;
                b=b->next;
            }
        }

        if(!a) tail->next=b;
        else tail->next=a;


        return head;

    }

    

    


public:
    ListNode* sortList(ListNode* head) {

        if(head == NULL || head ->next == NULL) return head;

        ListNode*slow=head;
        ListNode*fast=head;

        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode*temp=slow;
        temp=slow->next;
        slow->next=nullptr;


        ListNode*left=sortList(head);
        ListNode*right=sortList(temp);

        return merge(left,right);

        

        
        
        
    }
};