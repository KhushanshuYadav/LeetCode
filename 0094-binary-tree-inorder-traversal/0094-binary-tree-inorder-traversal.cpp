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
    vector<int> inorderTraversal(TreeNode* root) {

        //MORRIS

        vector<int>ans;
        TreeNode*curr=root;

        while(curr){

            if(!curr->left){  //means no left child so inorder says print that node and go right
                ans.push_back(curr->val);
                curr=curr->right;
            }

            else{

                //before going to left i want to have access of rightmost node of left subtree to create thread or delete if thread is already there 

                TreeNode*temp=curr->left;
                while(temp->right && temp->right!=curr){
                    temp=temp->right;
                }

                if(!temp->right){  //it means no thread was there so create

                    temp->right=curr;  //creating thread
                    curr=curr->left  ;  //going left
                    
                }
                else{//thread was there already means we have traversed the left subtree already
                    temp->right=nullptr;  //break
                    ans.push_back(curr->val); //as left is done so print curr
                    curr=curr->right;   //go to right

                }

            }



        }








        return ans;
        
    }
};