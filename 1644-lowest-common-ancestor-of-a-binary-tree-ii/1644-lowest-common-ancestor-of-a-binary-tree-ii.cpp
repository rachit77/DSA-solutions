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
     TreeNode* lcs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        TreeNode* l=lcs(root->left,p,q);
        TreeNode* r=lcs(root->right,p,q);
        
        if(l==NULL) return r;
        else if(!r) return l;
        else return root;
    }
    
    bool checkExist(TreeNode* root, TreeNode* s)
    {
        if(root==NULL) return false;
        if(root==s) return true;
        
        return checkExist(root->left,s) || checkExist(root->right,s);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL || p==NULL || q==NULL) return NULL;
        
        bool first=false, second=false;
         first=checkExist(root,p);
         second=checkExist(root,q);
        
        if(first==false || second==false) return NULL;
       return lcs(root,p,q) ;
    }
};