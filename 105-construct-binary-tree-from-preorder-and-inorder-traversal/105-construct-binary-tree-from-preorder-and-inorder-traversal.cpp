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
    TreeNode* find(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int> &mp, int &pre_id, int i_l,int i_r)
    {
        if(pre_id==preorder.size() || i_l<0 || i_r==inorder.size() || i_l>i_r)               return NULL;
        
        if(i_l==i_r)
        {
            return new TreeNode(preorder[pre_id]);
           // return NULL;
        }
        
        int i=mp[preorder[pre_id]];
        
        TreeNode* root=new TreeNode(preorder[pre_id]);
        pre_id++;
        root->left= find(preorder,inorder,mp,pre_id,i_l,i-1);
        if(root->left==NULL) pre_id--;
        pre_id++;
        root->right=find(preorder,inorder,mp,pre_id,i+1,i_r);
        if(root->right==NULL) pre_id--;
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //use pre order to find root
        unordered_map<int,int> mp;
       
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        
        int pre_id=0;
        TreeNode* root= find(preorder,inorder,mp,pre_id,0,inorder.size()-1);
        return root;
        
    }
};