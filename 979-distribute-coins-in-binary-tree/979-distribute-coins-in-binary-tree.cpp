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
    int distribute(TreeNode* node, int &moves) //function return the number of coins present at parent node
    {
       if(node==NULL) return 0;
        
        int l=distribute(node->left, moves);
        moves+= abs(l);
        
        int r=distribute(node->right,moves);
        moves+=abs(r);
        
        int coins= node->val-1+l+r;
        return coins;
    }
    
    int distributeCoins(TreeNode* root) {
        
        int moves=0;
        int coins=distribute(root,moves);
        
        //cout<<coins<<endl;
        // if(coins!=1) return -1;
        // else
        return moves;
    }
};