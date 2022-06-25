class LRUCache {
public:
    
    //Method-1 correct but TLE
//     queue<pair<int,int>> q1;
//     int siz=0;
//     LRUCache(int capacity) {
//         siz=capacity;
//     }
    
//     int get(int key) {
//         int rec=-1;
        
//        queue<pair<int,int>> q2;
//         int flag=1;
        
//         int k=q1.size();
        
//         while(k--)
//         {
//             pair<int,int> temp=q1.front();
//             q1.pop();
            
//             if(flag && temp.first==key)
//             {
//                 q1.push(temp); 
//                 rec=temp.second;
//                 flag=0;
//             }
//             else
//                q2.push(temp);
//         }
        
//         if(!q1.empty())
//         q2.push(q1.front());
        
//         q1=q2;
//         return rec; 
//     }
    
//     void put(int key, int value) {
//         if(q1.empty() && siz>0)
//         {
//             q1.push({key,value});
//             return;
//         }
       
//         queue<pair<int,int>> q2;
//         int flag=1;
        
//         int k=q1.size();
//         pair<int,int> rec;
        
//         while(k--)
//         {
//             pair<int,int> temp=q1.front();
//             q1.pop();
            
//             if(flag && temp.first==key)
//             {
//                 temp.second= value;
//                 q1.push(temp); 
//                 flag=0;
//             }
//             else
//                q2.push(temp);
//         }
        
//         if(!q1.empty()) //update
//         q2.push(q1.front());
//         else   //add new
//         {
//             if(q2.size()==siz) q2.pop();
//             q2.push({key,value}); 
//         }
//         q1=q2;  
//     }
    
    struct Node {
        int key,val;
        Node* next,*prev;
        
        Node(int _key,int _val)
        {
            key=_key;
            val=_val;
            next=NULL;
            prev=NULL;
        }
    };
    
    int cap;
    unordered_map<int,Node*>mp;
    
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    
    LRUCache(int capacity) {
       cap=capacity; 
    
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(Node* newnode)
    {
        Node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    
    void deleteNode(Node* temp)
    {
        Node* k=temp->next;
        temp=temp->prev;
        
        temp->next=k;
        k->prev=temp;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node* temp=mp[key];
            int res=temp->val;
            
            deleteNode(temp);
            addNode(temp);
            mp[key]=head->next;
            
            return res;
        }
        
        else return -1;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()) //already present in map
        {
          Node* existingNode=mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */