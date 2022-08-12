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
public:
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL) return NULL;
        
        if(root==p || root==q) return root;
        
      TreeNode* a= find(root->left,p,q);
        
       TreeNode* b= find(root->right,p,q);
        
        if(a==NULL)
            return b;
        else if(b==NULL)
            return a;
        else
            return root;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return find(root,p,q);
        
    }
};