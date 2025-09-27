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
    int countNodes(TreeNode* root) {

        int lH=0;
        int rH=0;

        TreeNode*curr=root;

        while(curr){
            lH++;
            curr=curr->left;
        }

        curr=root;

        while(curr){
            rH++;
            curr=curr->right;
        }

        if(lH==rH) return pow(2,lH)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};