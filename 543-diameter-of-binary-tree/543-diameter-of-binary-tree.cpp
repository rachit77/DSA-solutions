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
    int  find(TreeNode* root, int h)
    {
        if(root==NULL) return 0;
        
        int l=find(root->left, h+1);
        int r= find(root->right,h+1);
        
        ans=max(ans,l+r);
        //cout<<l+r<<endl;
        return 1+max(l,r);
        
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int h=0;
        find(root,h);
        return ans;
        
    }
};