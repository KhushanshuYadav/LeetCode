/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {

    Node*fun1(Node* head){

        Node*curr=head;
        while(curr){
            Node*temp=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=temp;
            curr=temp;
        }

        return head;
    }

    Node*fun2(Node*head){
        Node*curr=head;

        while(curr){
            if(curr->random) curr->next->random=curr->random->next;

            else curr->next->random=NULL;

            curr=curr->next->next;
            
        }

        return head;
    }

    Node*fun3(Node*head){
        Node*curr=head;
        head=curr->next;

        while(curr){
            //if(curr==head)

            Node*temp=curr->next->next;
            if(curr->next->next) curr->next->next=curr->next->next->next;
            
            curr->next=temp;
            curr=temp;
        }

        return head;
    }
public:
    Node* copyRandomList(Node* head) {

        if(!head) return head;


        head=fun1(head);

        head=fun2(head);
        head = fun3(head);







        return head;
    }
};