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
    int ans=INT_MIN;
    int sum(TreeNode* node)
    {
        if(node==NULL) return 0;
        
        int l= sum(node->left);
        int r= sum(node->right);
        
        int a=node->val+l+r;
        int b=node->val +l;
        int c=node->val +r;
        int d=node->val;
        
        int e=max(a,b);
        int f=max(c,d);
        int g= max(e,f);
        
        ans=max(ans,g);
        
        e=max(b,f);
        e=max(e,0);
        
        return e;
    }
    int maxPathSum(TreeNode* root) {
        sum(root);
        return ans;
    }
};