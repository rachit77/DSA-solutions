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

    int find(TreeNode* node, int &ans)
    {
        if(node==NULL)
        {
            //under observation
            return 2;
        }
        
        int a= find(node->left,ans);
        int b= find(node->right,ans);
        
        if(a==1 || b==1) // if anyone child has no camera
        {
            ans++;
            return 3;
        }
        
      else if(a==3 || b==3) //if any child has a camera 
        {
            // parent is under observation
            return 2;
        }
        
    // only case left when both child are under observation and in that case parent need no camera
            
        else
            return 1;
    }
    
     int minCameraCover(TreeNode* root)  {
         
         if(root==NULL)  return 0;
         // 1-> no camera
         // 2-> under observation
         // 3-> camera present
        
         int ans=0;
         int head=find(root,ans);
         
         if(head==1) ans++;
         
         return ans;
         
     }
};