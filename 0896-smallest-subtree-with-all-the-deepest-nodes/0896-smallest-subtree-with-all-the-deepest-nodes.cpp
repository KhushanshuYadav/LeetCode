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

    unordered_map<int,int>m;//node->val,depth
    int maxDepth=INT_MIN;

    void depthMap(TreeNode*root,int depth){

        if(!root) return ;

        //pre order
        maxDepth=max(maxDepth,depth);
        m[root->val]=depth;
        depthMap(root->left,depth+1);
        depthMap(root->right,depth+1);

    }
    TreeNode* lca(TreeNode*root,int& maxDepth){

        if(root==nullptr || m[root->val]==maxDepth) return root;

        TreeNode* left=lca(root->left,maxDepth);
        TreeNode* right=lca(root->right,maxDepth);

        if(left && right) return root;

        return (left!=nullptr?left:right);

        
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        depthMap(root,0);

        return lca(root,maxDepth);

        
    }
};