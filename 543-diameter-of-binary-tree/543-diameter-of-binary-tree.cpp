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
    int ans=0;
    int  find(TreeNode* root, int &dia)
    {
        if(root==NULL) return 0;
        
        int l=find(root->left, dia);
        int r= find(root->right,dia);
        
        dia=max(dia,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        find(root,dia);
        return dia;
    }
};