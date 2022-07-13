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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root==NULL) return ans;
        
        
        queue<TreeNode*> q;
        q.push(root);
       
        
        while(!q.empty())
        {
            double temp=0;
            int cur_size=q.size();
            
            
            for(int i=0;i<cur_size;i++)
            {
                TreeNode* curr=q.front();
                temp= temp+ curr->val;
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
            }
            temp= temp/cur_size;
            ans.push_back(temp);
        }
        
        return ans;
    }
};