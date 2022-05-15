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
    void sumL(TreeNode* root, int *sum, int *h, int ch )
    {
        if(root==NULL)
            return;
        
       if(*h<ch){
           *h=ch;
           *sum=root->val;
       }
        else if(*h ==ch)
        {
            *sum+=root->val;
        }
        
        sumL(root->left, &(*sum),&(*h),ch+1);
        sumL(root->right, sum,h,ch+1);
        
        return;
    }
    
    
    int deepestLeavesSum(TreeNode* root) {
        
        int sum=0,h=0,ch=0;
        sumL(root,&sum,&h,ch);
        
        return sum;
    }
};