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
    bool func(TreeNode* r,TreeNode* l){
        if(l==nullptr && r==nullptr) return true;
         if(l==nullptr || r==nullptr) return false;


       return (r->val==l->val) && func(r->right,l->left) && func(r->left,l->right);
        

    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        else return func(root->right,root->left);
    }
};