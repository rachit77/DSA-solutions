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
    TreeNode* find(TreeNode* node, int val)
    {
        if(node==NULL)
            return NULL;
        
        if(node->val ==val)
            return node;
        
        TreeNode* temp=find(node->left,val);
        if(temp!=NULL)
            return temp;
        
        temp=find(node->right,val);
        if(temp!=NULL)
            return temp;
        
        return NULL;
            
        
        
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        
        return find(root,val);
            
    }
};