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

    private:
    //by considering the root as lca this code return a vector having each element is distance of each leaf node from it
    vector<int>postOrder(TreeNode* root, int& distance,int& ans){

        vector<int>p={};

        if(!root) return p ;                 //at null so it cant have left and right child whem either left or right exits so we fall here

        if(!root->left && !root->right){
            p.push_back(1);
            return p;                     //curent node is leaf so no need to go left and right the leaft node as it disatnce from its parent


        }

        vector<int>left=postOrder(root->left,distance,ans);
        vector<int>right=postOrder(root->right,distance,ans);

        for(int i:left){
            for(int j:right){
                if(i+j<=distance) ans++;          //check for all pairs
            }
        }

                       //combine and return a vector with increased distance by one as onee node above


        for(int i:left){
            if(i+1<distance) p.push_back(i+1);   //we can inc by one all values and push but we know that if curr dis is >=dis so adding any d to it make it >d so no point of sending greater distances

        }

        for(int i:right){
            if(i+1<distance) p.push_back(i+1);
        }


        return p;








    }
public:
    int countPairs(TreeNode* root, int distance) {

        //more intutive code;
        int ans=0;
        postOrder(root,distance,ans);
        return ans;
        
        
    }
};