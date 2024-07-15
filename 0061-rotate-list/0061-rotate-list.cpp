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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next) return head;

        int len=1;

        ListNode*curr=head;
        while(curr->next){
            curr=curr->next;
            len++;
        }

        k=k%len;

        //curr->next=head;
        ListNode*temp=head;
        for(int i=1;i<len-k;i++){
            temp=temp->next;
        }

        curr->next=head;
        head=temp->next;
        temp->next=NULL;
        
        return head;
    }
};