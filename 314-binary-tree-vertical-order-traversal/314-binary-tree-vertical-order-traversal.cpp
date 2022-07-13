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
    void find_breadth(TreeNode* root, int &l, int &r, int cur)
    {
        if(root==NULL) return;
        
        if(cur<l) l=cur;
        if(cur>r) r=cur;
        
        find_breadth(root->left,l,r,cur-1);
        find_breadth(root->right,l,r, cur+1);
        
        return;
    }
    
    void vertical_transversal(TreeNode* root, vector<vector<int>> &ans,int cur, int &shift)
    {
        if(root==NULL) return;
        
        queue<pair<TreeNode*, int>> q; //node, width
        q.push({root,0});
        
        while(!q.empty())
        {
            int cur_size=q.size();
            
            for(int i=0;i<cur_size;i++)
            {
                pair<TreeNode*, int> curr= q.front();
                q.pop();
                
                ans[curr.second+shift].push_back(curr.first->val);
                
                if(curr.first->left) q.push({curr.first->left, curr.second-1});
                if(curr.first->right) q.push({curr.first->right, curr.second+1});
                    
            }
        }
        
        return;
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        int l=0,r=0,cur=0;
        
        find_breadth(root,l,r,cur);
        
        int width=r-l+1;
        
        if(root==NULL) width=0;
        
        vector<vector<int>> ans(width);
        
        l=abs(l);
        vertical_transversal(root,ans,cur,l);
        
        return ans;
    }
};