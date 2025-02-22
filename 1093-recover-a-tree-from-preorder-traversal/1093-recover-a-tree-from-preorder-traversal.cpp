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
    TreeNode* recoverFromPreorder(string traversal) {

        int n =traversal.size();
        unordered_map<int,TreeNode*>latestN;      //depth d,latest node at d
        unordered_map<TreeNode*,int>childCount;   //node,child count of node


        string s="";
        int i=0;
        while(i<n && traversal[i]!='-'){
            s.push_back(traversal[i]);
            i++;

        }

        int num=stoi(s);
        
        TreeNode*root=new TreeNode(num);
        latestN[0]=root;
        childCount[root]=0;

        int depth=1;
        i++;

        for(;i<n;i++){

            if(traversal[i]=='-') {
                depth++;
                continue;
            }

            string s="";

            while( i<n && traversal[i]!='-'){
                s.push_back(traversal[i]);
                i++;

            }

            int num=stoi(s);

            TreeNode* currNode=new TreeNode(num);

            TreeNode* parent=latestN[depth-1];

            int cC=childCount[parent];

            if(cC==0){
                //currNode is left child
                if(parent) parent->left=currNode;

            }
            else if(cC==1){
                //currNode is right child
                if(parent) parent->right=currNode;

            }

            latestN[depth]=currNode;
            childCount[parent]++;
            childCount[currNode]=0;

            depth=1;

        }

        return root;
        
    }
};