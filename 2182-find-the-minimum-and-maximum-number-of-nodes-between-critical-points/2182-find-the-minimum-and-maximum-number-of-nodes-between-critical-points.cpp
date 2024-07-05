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
    /*bool isCriticalPoint(ListNode*&node,ListNode*&prev){

        return 
        (





        );

    }*/
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode*curr=head->next;
        ListNode*prev=head;
        vector<int>ans(2,-1);
        vector<int>v;
        int pos=2;  //curr is at second node

        while( curr){


            if( curr->next && (curr->val > prev->val && curr->val > curr->next->val) ){
                v.push_back(pos);
            }

            else if( curr->next && (curr->val < prev->val && curr->val < curr->next->val) ){
                v.push_back(pos);
            }
            
            pos++;
            prev=curr;
            curr=curr->next;
        }

        if(v.size()<2) return ans;
        
        
        int mn=INT_MAX;
        for(int i=1;i<v.size();i++){
            mn=min(mn,v[i]-v[i-1]);
        }
        
        ans[0]=mn;
        ans[1]=v[v.size()-1]-v[0];
        return ans;

        

        

    }
};