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
    TreeNode* lcs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL) return NULL;
        
        if(root==p || root==q) return root;
        
        TreeNode* l=lcs(root->left, p,q);
        TreeNode* r=lcs(root->right,p,q);
        
        if(l==NULL) return r;
        else if(r==NULL) return l;
        else return root;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        
        TreeNode* res=nodes[0];
        
        for(int i=1;i<nodes.size();i++)
        {
            res=lcs(root,res,nodes[i]);
        }
        
        return res;
    }
};