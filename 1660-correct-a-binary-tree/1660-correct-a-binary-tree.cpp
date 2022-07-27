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
    TreeNode* find_child(TreeNode* root, unordered_map<TreeNode*,int> &mp)
    {
        if(root==NULL) return root;
        
        if(mp.find(root)!=mp.end()) //root is present
        {
            return root;
        }
        mp[root]=1;
        
        TreeNode* a=NULL, *b=NULL;
        a=find_child(root->left,mp);
        b=find_child(root->right,mp);
        
        if(a!=NULL) return a;
        else return b;
    }
    
    void find_parent(TreeNode* root,TreeNode* c,int h,vector<pair<TreeNode*,int>> &par)
    {
        if(root==NULL) return;
        
        if(root->left==c || root->right==c)
        {
           par.push_back({root,h});
        }
        
        find_parent(root->left,c,h+1,par);
        find_parent(root->right,c,h+1,par);
        
        return;
    }
    
    void find(TreeNode** root,TreeNode* temp)
    {
        if(*root==NULL) return;
        
        if(*root==temp) 
        {
            *root=NULL;
            return;
        }
        
        find(&((*root)->left),temp);
        find(&((*root)->right),temp);
        return;
    }
    
    TreeNode* correctBinaryTree(TreeNode* root) {
        // store the height of all nodes in a unordered map
        unordered_map<TreeNode*,int> mp;
        
       TreeNode* c= find_child(root,mp);
        
        if(c==NULL) return root;
        //find both the parents of c
        
        vector<pair<TreeNode*,int>> par; // node,depth
        
        find_parent(root,c,0,par);
        
        //find the parent with greater depth
        TreeNode* temp;
        if(par[0].second>par[1].second)
            temp=par[0].first;
        else
            temp=par[1].first;
        
       // cout<<temp->val<<endl;
        
        find(&root,temp);
        return root;
    }
};