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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {

        if(!root) return false;

        bool ans=solve(root,head);

        return ans;
        
    }

private:

    //return true if we find downward LL
    //from each node of tree
    bool solve(TreeNode* root,ListNode* head){

        if(!root) return false;

        //check for LL from current node
        if( preOrder(root,head) ) return true;

        //if not found check from left and right;

        bool leftCall=solve(root->left,head);
        if(leftCall) return true;


        bool rightCall=solve(root->right,head);
        if(rightCall) return true;

        return false;

    }

    bool preOrder(TreeNode* root,ListNode* head){

        if(!head) return true;

        if(!root) return false;

        if(root->val != head->val) return false;

        bool leftCall=preOrder(root->left,head->next);
        if(leftCall) return true;

        bool rightCall=preOrder(root->right,head->next);
        if(rightCall) return true;

        return false;


    }
};