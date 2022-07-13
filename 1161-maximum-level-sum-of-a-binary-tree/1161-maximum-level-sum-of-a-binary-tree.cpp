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
    int maxLevelSum(TreeNode* root) {
        
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level=0,l=0;
        int max_sum=INT_MIN;
        while(!q.empty())
        {
            l++;
            int cur_size=q.size();
            int level_sum=0;
            for(int i=0;i<cur_size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                
                level_sum+= curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            if(level_sum >max_sum)
            {
                max_sum=level_sum;
                level=l;
            }
        }
        
        return level;
    }
};