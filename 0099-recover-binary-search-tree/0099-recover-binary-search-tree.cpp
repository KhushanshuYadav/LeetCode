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

    void inOrder(TreeNode*root,TreeNode*&prev,TreeNode*&n1,TreeNode*& n2){

        if(!root) return;

        inOrder(root->left,prev,n1,n2);

        if(!n1 && prev && prev->val>root->val) {
            n1=prev;
            n2=root;
        }

        else if(prev && prev->val>root->val) n2=root;

        prev=root;


        inOrder(root->right,prev,n1,n2);

    }


public:
    void recoverTree(TreeNode* root) {

        TreeNode*prev=nullptr;
        TreeNode*n1=nullptr;
        TreeNode*n2=nullptr;

        inOrder(root,prev,n1,n2);

        swap(n1->val,n2->val);
    }
};