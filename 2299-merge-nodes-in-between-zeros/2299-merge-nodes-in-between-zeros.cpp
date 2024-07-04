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
    ListNode* mergeNodes(ListNode* head) {

        ListNode*prev=head;
        ListNode*newHead=head;
        ListNode*curr=head->next;

        while(curr  ){

            if(curr->val==0){

                if(!curr->next) prev->next=nullptr;

                else prev->next=curr;
                prev=curr;
                curr=curr->next;

            }
            else{

                prev->val+=curr->val;
            //ListNode*temp=curr;
            curr=curr->next;
            //delete(temp);

            }

            
        }

        return newHead;
        
    }
};