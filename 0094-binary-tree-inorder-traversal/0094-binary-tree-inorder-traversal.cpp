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

    void preorder(TreeNode* root,vector<int>&arr){
        if(root==NULL){
            return;
        }

        
        preorder(root->left,arr);
         arr.push_back(root->val);
        preorder(root->right,arr);
       
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>arr;

        preorder(root,arr);

        return arr;

    }
};