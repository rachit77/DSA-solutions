/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/



class Solution {
public:
    void dfs(Node* copy, Node* node, vector<Node*> &vis) 
    {
        vis[node->val]= copy;
        
        for(auto x: node->neighbors) {
            if(vis[x->val] ==NULL)  //not visited
            {
               Node* newNode= new Node(x->val);
                (copy->neighbors).push_back(newNode);
                dfs(newNode,x,vis);
            }
            else {
                (copy->neighbors).push_back(vis[x->val]);
                
            }
        }
    }
    
    
    Node* cloneGraph(Node* node) {
        
        if(node == NULL)
            return NULL;
        vector<Node*> vis(101,NULL);
        Node* copy= new Node(node->val);
        
        
        dfs(copy,node,vis);
        return copy;
        
    }
};