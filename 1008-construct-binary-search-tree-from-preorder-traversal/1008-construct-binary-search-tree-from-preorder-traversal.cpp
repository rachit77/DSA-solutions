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
//     void makeTree(TreeNode* node, int i)
//     {
//         if(node==NULL)
//         {
//             node=new TreeNode(i);
//             return;
//         }
//         if(i>node->val)
//             makeTree(node->right,i);
//         else
//             makeTree(node->left,i);
        
//         return;
//     }
    
    TreeNode* makeTree(TreeNode* node, int i)
    {
        if(node==NULL)
        {
            node=new TreeNode(i);
            return node;
        }
        if(i>node->val)
           node->right= makeTree(node->right,i);
        else
           node->left= makeTree(node->left,i);
        
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* root=NULL;
        for(auto x:preorder)
        {
            TreeNode* node=root;
            root= makeTree(node,x);
        }
        
        return root;
    }
};