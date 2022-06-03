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
    void find(TreeNode* root, vector<int> &v, int &h)
    {
        if(root==NULL) return;
        if(v.size()==h) v.push_back(root->val);
        
        h++;
        find(root->right, v, h);
        find(root->left, v,h);
        h--;
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int h=0;
        find(root,ans,h);
        return ans;
    }
};