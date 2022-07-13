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
    int find_height(TreeNode* root)
    {
        if(root==NULL) return 0;
        int l=0,r=0;
        
        l=find_height(root->left);
        r=find_height(root->right);
        
        return 1+max(l,r);
    }
    
    void level_order(TreeNode* root, vector<vector<int>> &ans, int &h, int cur_h)
    {
        if(root==NULL) return;
        
        ans[h-cur_h-1].push_back(root->val);
        
        //left side
        level_order(root->left,ans,h,cur_h+1);
        //right side
        level_order(root->right,ans,h,cur_h+1);
        
        return;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
 
        
        //method-1
//         vector<vector<int>> ans;
//         if(!root) return ans;
        
//         queue<TreeNode*> q;
//         q.push(root);
        
//         stack<vector<int>> st;
        
//         while(!q.empty())
//         {
//             int siz=q.size();
//             vector<int> temp;
//             for(int i=0;i<siz;i++)
//             {
//                 TreeNode* node=q.front();
//                 q.pop();
//                 temp.push_back(node->val);
                
//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//             }
//             st.push(temp);
//         }
        
//         while(!st.empty())
//         {
//             ans.push_back(st.top());
//             st.pop();
//         }
        
//         return ans;
        
        
        //method-2
        int h=find_height(root);
        vector<vector<int>> ans(h);
        int cur_h=0;
        level_order(root,ans,h,cur_h);
        
        return ans;
    }
};