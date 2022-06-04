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
    bool check(TreeNode* root, long int ma, long int mi)
    {
        if(root==NULL) return true;
        
       if(root->val >=ma || root->val<=mi) return false;
        
        bool a=check(root->left,root->val,mi);
        bool b=check(root->right,ma,root->val);
        
       return a&&b; 
    }
    
    bool isValidBST(TreeNode* root) {
        
        long a=LONG_MAX;
        long b=LONG_MIN;
        
        return check(root,a, b);
        //return true;
    }
};