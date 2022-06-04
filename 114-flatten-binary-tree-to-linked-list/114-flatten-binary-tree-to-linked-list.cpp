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
    void preorder(TreeNode* root, queue<TreeNode*> &q)
    {
        if(root==NULL) return;
        
        q.push(root);
        preorder(root->left,q);
        preorder(root->right,q);
        
        return;
    }
    void flatten(TreeNode* root) {
        
        if(root==NULL) return;
    queue<TreeNode*> q;
    preorder(root,q);
        
        int siz=q.size();
        for(int i=0;i<siz-1;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            
            temp->right=q.front();
            temp->left=NULL;
        }
        
        TreeNode* temp=q.front();
        temp->left=NULL;
        temp->right=NULL;   
    }
};