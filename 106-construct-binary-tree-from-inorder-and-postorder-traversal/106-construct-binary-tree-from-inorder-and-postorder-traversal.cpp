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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,unordered_map<int,int> &mp,int &post_id, int il,int ir)
    {
        if(il<0 || ir>=inorder.size() || il>ir || post_id<0)
            return NULL;
        
        if(il==ir)
        {
            return new TreeNode(postorder[post_id]);
        }
        
        int i=mp[postorder[post_id]];
        
        cout<<postorder[post_id]<<endl;
        TreeNode* root= new TreeNode(postorder[post_id]);
        
        post_id--;
        root->right= solve(inorder,postorder, mp,post_id,i+1,ir);
        if(!root->right) post_id++;
        
        post_id--;
        root->left= solve(inorder,postorder, mp,post_id,il,i-1);
        if(!root->left) post_id++;
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //post order contains root || right->left->root
        
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        
        int post_id=postorder.size()-1;
        return solve(inorder,postorder,mp, post_id,0,inorder.size()-1);
        
    }
};