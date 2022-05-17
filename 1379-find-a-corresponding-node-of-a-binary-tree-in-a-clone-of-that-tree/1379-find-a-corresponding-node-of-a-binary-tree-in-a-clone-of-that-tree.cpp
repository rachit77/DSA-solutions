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
    
    
    void find(TreeNode* root, TreeNode* cloned, TreeNode* target)
    {
        if(root==NULL) return;
        
        if(root==target)
        {
            ans=cloned;
            return;
        }
        
        find(root->left,cloned->left, target);
        find(root->right,cloned->right,target);
        
        return;

    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
         find(original,cloned,target);
        return ans;
    }
    
    private:
    TreeNode* ans;
};