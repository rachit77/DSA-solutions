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
    bool isCousins(TreeNode* root, int x, int y) { 
        
        //check if both of them are on same level
        
        queue<TreeNode*> q;
        q.push(root);
        int flag=0,par=0;
        
        
        
        while(!q.empty())
        {
            int cur_size=q.size();
            
            for(int i=0;i<cur_size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                
                if(curr->val==x || curr->val==y) flag++;
                
                int l=0,r=0;
                if(curr->left)
                {
                    if(curr->left->val==x || curr->left->val==y) l=1;
                    q.push(curr->left);
                }
                
                if(curr->right)
                {
                    if(curr->right->val==x || curr->right->val==y) r=1;
                    q.push(curr->right);
                }
                
                if(l==1 && r==1)
                {
                    par=1;
                    break;
                }
            }
            
            if(flag!=0) break;
        }
        
        if(par==0 && flag==2) return true;
        
         return false;
        
    }
};