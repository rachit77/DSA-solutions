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
    void sum(TreeNode* root, int &low, int &high, int &ans)
    {
       if(!root) return ;
        
       if(root->val >=low && root->val <= high)  ans+=root->val;
        
       if(low<=root->val) sum(root->left,low,high,ans);
       if(high>=root->val) sum(root->right,low,high,ans);
        return;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        sum(root,low,high,ans); 
        return ans;
    }
};