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
    int mod=1e9+7;
    int sum(TreeNode*root){

        if(!root) return 0;

        int ans=root->val;

        if(root->left) ans+=sum(root->left);
        if(root->right) ans+=sum(root->right);

        return ans;
    }

    int solve(TreeNode*root,long long&ans,int&t){

        if(!root) return 0;

        int s=root->val;

       
        if(root->left) s+=solve(root->left,ans,t);
        
        if(root->right) s+=solve(root->right,ans,t);

        long long restTreeSum=t-s;
        ans=max(ans,s*restTreeSum);
        

        
        

        return s;
    }
public:
    int maxProduct(TreeNode* root) {

        long long ans=0;

        TreeNode*temp=root;

        int s=sum(temp);

        solve(temp,ans,s);

        return int(ans%mod);
        
    }
};