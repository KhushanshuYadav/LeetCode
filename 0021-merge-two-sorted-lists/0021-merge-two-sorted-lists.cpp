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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode*head=NULL,*tail=NULL;
        ListNode*curr1=list1,*curr2=list2;

        while(curr1 && curr2){
            if(curr1->val<=curr2->val){
                if(!head && !tail){
                    head=tail=curr1;
                    
                }
                else{
                    tail->next=curr1;
                    tail=curr1;
                   
                }
                curr1=curr1->next;
            }

            else{
                if(!head && !tail){
                    head=tail=curr2;
                   
                }
                else{
                    tail->next=curr2;
                    tail=curr2;
                   
                }
                 curr2=curr2->next;
            }
        }

        while(curr1){

             if(!head && !tail){
                    head=tail=curr1;
                    
                }
                else{
                    tail->next=curr1;
                    tail=curr1;
                    
                }
                curr1=curr1->next;
            
        }

        while(curr2){
           if(!head && !tail){
                    head=tail=curr2;
                    
                }
                else{
                    tail->next=curr2;
                    tail=curr2;
                    
                }
                curr2=curr2->next;
        }

        return head;
        
    }
};