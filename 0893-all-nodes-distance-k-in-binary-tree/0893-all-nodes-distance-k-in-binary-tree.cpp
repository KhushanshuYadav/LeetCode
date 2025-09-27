/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    void solve( TreeNode* curr,int d,int& k,unordered_set<TreeNode*>& vis,vector<int>& ans,unordered_map<TreeNode*,TreeNode*>&parent ){

        vis.insert(curr);

        if(d==k) ans.push_back(curr->val);

        if(d<k && curr->left && !vis.count(curr->left)) solve(curr->left,d+1,k,vis,ans,parent);

        if(d<k && curr->right && !vis.count(curr->right)) solve(curr->right,d+1,k,vis,ans,parent);

        if(d<k && parent[curr] && !vis.count(parent[curr])) solve(parent[curr],d+1,k,vis,ans,parent);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*,TreeNode*>parent;

        queue<TreeNode*>q;

        TreeNode*temp=nullptr;

        q.push(root);

        while(!q.empty()){

            TreeNode*node=q.front();
            q.pop();

            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }

            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }


        TreeNode*curr=target;

        unordered_set<TreeNode*>vis;

        vector<int>ans;


        solve(curr,0,k,vis,ans,parent);

        return ans;




        
    }
};