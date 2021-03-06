/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node *prev=NULL;
    Node *head=NULL;
   
    
    void convert(Node* root)
    {
        if(root==NULL) return;
        
        convert(root->left);
        
        //process the root
         if(prev==NULL)
         {
             head=root;
         }
        else
        {
            prev->right=root;
            root->left=prev;
        }
         prev=root;
        
        convert(root->right);
    }
    
    Node* treeToDoublyList(Node* root) {
        
        //sorted by inorder transversal
        // inorder  left->root->right
        if(root==NULL) return NULL;
        
        convert(root);
        
        prev->right=head;
        head->left=prev;
        return head;
    }
};