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
    
    // method-1  TC: N
//     void find(TreeNode* root, int &ans)
//     {
//         if(root==NULL) return;
        
//         ans++;
//         find(root->left,ans);
//         find(root->right, ans);
        
//         return;
//     }
//     int countNodes(TreeNode* root) {
//         if(root==NULL) return 0;
//         int ans=0;
//         find(root, ans);
//         return ans;
//     }
    
    //method-2 Binary seach on leaf nodes TC: (log n)^2
    int depth(TreeNode* root)
    {
        if(!root) return 0;
        return 1+ max(depth(root->left), depth(root->right));
    }
    
    bool nodeExists(TreeNode* root, int val, int d)
    {
        int lo=0,hi=pow(2,d-1)-1;
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            
            if(val<=mid) //present in left half
            {
                 hi=mid;
                root=root->left;
            }
            else
            {
                lo=mid+1;
                root=root->right;
            }      
        }
        
        return root;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int d= depth(root); // 1-based indexing
        int ans= pow(2,d-1)-1;
        
        int lo=0,hi=pow(2,d-1)-1;
        
        while(lo<hi)
        {
            int mid= lo+(hi-lo+1)/2;
            cout<<mid<<endl;
            if(nodeExists(root, mid,d))
                lo=mid;
            else
                hi=mid-1;
            // cout<<"eve";
            // cout<<lo<<endl;
        }
        
        // cout<<ans<<endl;
        // cout<<lo<<endl;
        ans= ans+lo+1;
        return ans;
    }
};