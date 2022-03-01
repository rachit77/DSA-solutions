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
    
    
    int widthOfBinaryTree(TreeNode* root) {
      if(root==NULL)
          return 0;
        
        queue<pair<TreeNode*, long long int>> q;
        int ans=0;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            int siz=q.size();
            
            int mmin=q.front().second;
            
            int mi,ma;
            
            for(int i=0;i<siz;i++)
            {
                long long int cur_id= q.front().second -mmin;
                
                TreeNode* temp =q.front().first;
                q.pop();
                
                if(i==0)
                    mi=cur_id;
                if(i==siz-1)
                    ma=cur_id;
                
                
    
                
                
                
                if(temp->left)
                {
                    q.push({temp->left,2*cur_id +1});
                }
                
                if(temp->right)
                    q.push({temp->right,2*cur_id+2});
                
            }
            
            ans= max(ans,ma-mi+1);
        }
        
         return ans;
    }
    
   
};