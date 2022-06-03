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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int cnt=0;
        stack<TreeNode*> st;
        vector<vector<int>> ans;
        if(!root) return ans;
        
        st.push(root);
        
        while(!st.empty())
        {
            int siz=st.size();
            vector<int> temp;
            stack<TreeNode*> st1;
            for(int i=0;i<siz;i++)
            {
                TreeNode* node=st.top();
                temp.push_back(node->val);
                st.pop();
                if(cnt%2==1)  // r and l
                {
                   if(node->right) st1.push(node->right);
                   if(node->left) st1.push(node->left);
                }
                else  // l and r 
                {
                  if(node->left) st1.push(node->left);
                  if(node->right) st1.push(node->right);
                }
            }
            ans.push_back(temp);
            cnt++;
            st=st1;
        }
        
        return ans;
        
    }
};