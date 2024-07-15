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

    ListNode*reverse(ListNode*head){
        ListNode*curr=head,*prev=NULL;
        while(curr){
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        return prev;
    }

    ListNode*getKThNode(ListNode*head,int k){

        k--;

        ListNode*ans=head;

        while(k--){

            ans=ans->next;

        }
        return ans;

    }


    ListNode* reverseKGroup(ListNode* head, int k) {

        int len=1;
        ListNode*curr=head;
        while(curr->next){
            curr=curr->next;
            len++;
        }

        int x=len%k;
        int y=len-x;

        ListNode*mark=head;

        while(y--) mark=mark->next;

        ListNode*tempHead=head;
        ListNode*firstPrev=NULL;
        ListNode*global=NULL;
        bool flag=true;
        while(tempHead!=mark){

            ListNode*kThNode=getKThNode(tempHead,k);
            ListNode*nextNode=kThNode->next;
            kThNode->next=NULL;

            
            if(flag){
                head=reverse(tempHead);
                flag=false;
            }
            else{
                firstPrev->next=reverse(tempHead);
            }
            
            
            firstPrev=tempHead;
            tempHead=nextNode;
            global=nextNode;
        }

        firstPrev->next=global;

        return head;

        
    }
};