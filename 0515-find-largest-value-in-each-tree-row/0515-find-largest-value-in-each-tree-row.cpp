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
    vector<int> largestValues(TreeNode* root) {

        if(!root) return {};
        
        vector<int>ans;
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){

            int n=q.size();
            int mx=INT_MIN;
            while(n--){

                TreeNode*node=q.front();
                mx=max(mx,node->val);
                q.pop();

                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);


            }

            ans.push_back(mx);
        }

        return ans;
    }
};