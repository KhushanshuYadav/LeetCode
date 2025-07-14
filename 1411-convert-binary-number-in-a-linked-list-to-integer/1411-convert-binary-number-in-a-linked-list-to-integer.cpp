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
    int getDecimalValue(ListNode* head) {

        vector<int>TwoPower(30,1);

        for(int i=1;i<30;i++){
            TwoPower[i]=TwoPower[i-1]*2;
            cout<<TwoPower[i]<<endl;
        }

        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;

        }
        cout<<n<<endl;

        temp=head;

        int ans=0;

        for(int i=n-1;i>=0;i--){

            if(temp->val!=0) {
                ans+=((temp->val)*TwoPower[i]);
                cout<<ans<<endl;
                }
                temp=temp->next;

        }

        return ans;

        
    }
};