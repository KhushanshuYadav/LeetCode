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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_set<int>s;

        for(int &num:nums){
            s.insert(num);
        }


        ListNode*curr=head;
        ListNode*prev=nullptr;

        while(curr){

            if( s.count(curr->val) ){

                if(curr==head){
                    
                    head=curr->next;
                    curr->next=nullptr;
                    curr=head;

                }

                else{

                    prev->next=curr->next;
                    curr->next=nullptr;
                    curr=prev->next;




                }

            }

            else{
                prev=curr;
                curr=curr->next;

            }
        }

        return head;
        
    }
};