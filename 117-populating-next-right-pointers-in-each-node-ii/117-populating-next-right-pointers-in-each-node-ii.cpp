/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root)
            return root;
        
        queue<pair<Node*,int>> q;
        Node* head=root;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            // cout<<q.front().first;
            // q.pop();
            
            
            //queue<pair<Node*,int>> k;
           // queue<pair<Node*,int>> temp;
            
           auto temp = q.front();
            q.pop();
            
           // cout<<typeid(temp).name()<<endl;
            
            if(q.empty())
                temp.first->next=NULL;
            else
            {
               auto k=q.front();
                if(temp.second == k.second)
                    temp.first->next=k.first;
                else
                    temp.first->next=NULL;
            }
            
            
            if(temp.first->left)
                q.push({temp.first->left, temp.second+1});
            
            if(temp.first->right)
                q.push({temp.first->right, temp.second+1});
            
            
            
        }
        
        return root;
        
    }
};