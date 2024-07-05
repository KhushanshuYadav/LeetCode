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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode*curr=head->next;
        ListNode*prev=head;
        vector<int>ans(2,-1);
        //vector<int>v;
        int pos=2;  //curr is at second node
        int prevPos=-1;
        int mn=INT_MAX;
        int mx=INT_MIN;
        int firstCPos=-1;

        while( curr){


            if( curr->next && (curr->val > prev->val && curr->val > curr->next->val) ){
                //v.push_back(pos);
                if(prevPos==-1){
                    prevPos=pos;
                    firstCPos=pos;
                }
                else{

                    mn=min(mn,pos-prevPos);
                    prevPos=pos;

                }
            }

            else if( curr->next && (curr->val < prev->val && curr->val < curr->next->val) ){
               if(prevPos==-1){
                    prevPos=pos;
                    firstCPos=pos;
                }
                else{

                    mn=min(mn,pos-prevPos);
                    prevPos=pos;

                }
            }
            
            pos++;
            prev=curr;
            curr=curr->next;
        }

        if(firstCPos==1) return {-1,-1};
        if(mn==INT_MAX) return {-1,-1};

        return {mn,prevPos-firstCPos};

    }

    

    
};