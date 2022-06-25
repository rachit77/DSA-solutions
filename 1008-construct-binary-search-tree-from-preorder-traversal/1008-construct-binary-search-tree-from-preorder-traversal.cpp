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
    
    //method-1 TC: o(N^2)
//     TreeNode* makeTree(TreeNode* node, int i)
//     {
//         if(node==NULL)
//         {
//             node=new TreeNode(i);
//             return node;
//         }
//         if(i>node->val)
//            node->right= makeTree(node->right,i);
//         else
//            node->left= makeTree(node->left,i);
        
//         return node;
//     }
    
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
        
//         TreeNode* root=NULL;
//         for(auto x:preorder)
//             root= makeTree(root,x);
        
//         return root;
//     }
    
    // method-2 bst using preorder and inorder TC: Nlog(N)=>sorting the vector
    
    //method-3
    TreeNode* solve(int &i, vector<int>& preorder, int bound)
    {
        if(i>=preorder.size() || preorder[i]>=bound) return NULL;
        
        TreeNode* root= new TreeNode(preorder[i]);
        i++;
        
        root->left=solve(i,preorder,root->val);
        root->right=solve(i,preorder,bound);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder){
        
        int i=0;
        return solve(i,preorder,INT_MAX);
        
    }
};