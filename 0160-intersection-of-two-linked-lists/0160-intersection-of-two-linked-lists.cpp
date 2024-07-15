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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int len1=0,len2=0;

        ListNode*curr1=headA,*curr2=headB;



        while(curr1){
            len1++;
           curr1=curr1->next;

        }
        curr1=headA;

        while(curr2){
            len2++;
            curr2=curr2->next;
        }
        curr2=headB;

        int diff=abs(len1-len2);

        if(len1>=len2){

            for(int i=0;i<diff;i++){
                curr1=curr1->next;
            }

        }
        else{

            for(int i=0;i<diff;i++){
                curr2=curr2->next;
            }

        }

        while(curr1 && curr2){
            if(curr1==curr2) return curr1;

            curr1=curr1->next;
            curr2=curr2->next;
        }

        return NULL;
    }
};