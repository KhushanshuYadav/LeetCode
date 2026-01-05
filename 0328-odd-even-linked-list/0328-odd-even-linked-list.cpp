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
    ListNode* oddEvenList(ListNode* head) {

        if(!head || !head->next) return head;

        ListNode*odd=head;
        ListNode*even=head->next;
        ListNode*evenHead=head->next;

        int f1=1;
        int f2=1;

        while(f1 && f2){
            
            if(odd->next && odd->next->next){
                ListNode*nextOdd=odd->next->next;
                odd->next=nextOdd;
                odd=nextOdd;
            }

            else f1=0;
            

            if(even->next && even->next->next){
                ListNode*nextEven=even->next->next;
                even->next=nextEven;
                even=nextEven;
            }
            else f2=0;
        }

        if(even->next) even->next=nullptr;
        if(odd->next) odd->next=nullptr;


        odd->next=evenHead;


        return head;
        
    }
};