/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        
        unordered_map<Node*,bool> mp;
        
        while(p !=NULL)
        {
            mp[p]=true;
            p=p->parent;
        }
        
        while(q!=NULL && mp.find(q)==mp.end())
        {
            q=q->parent;
        }
        
        if(q!=NULL) return q;
        else
            return NULL;
    }
};