/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL) return head;
        
        Node* ptr=head;
        
        while(ptr) {
            
            Node *temp= new Node(ptr->val);
            
            temp->next=ptr->next;
            
            ptr->next=temp;
            
            ptr=ptr->next->next;
        }
        
//         ptr=head;
//         while(ptr) {
//             cout<<ptr->val<<endl;
//             ptr=ptr->next;
            
//         }
        
        ptr=head;
        
        Node* copy=head->next;
        Node* ans=head->next;   

        //set the random pointer now
        while(ptr) {
            
            Node *temp=ptr->random;
            
            if(temp==NULL) copy->random=NULL;
            else {
                copy->random=temp->next;
            }
            
            //ptr->next=ptr->next->next;
             ptr=ptr->next->next;
            
            if(copy->next!=NULL) {
                //copy->next=copy->next->next;
                copy=copy->next->next;
            }
        }
       
        
        //Now unlink the 2 linked list
        ptr=head;
        copy=head->next;
        
        while(ptr!=NULL) {
            ptr->next=ptr->next->next;
            ptr=ptr->next;
            
            if(copy->next!=NULL)
            copy->next= copy->next->next;
            copy=copy->next;
        }
        
//                 ptr=head->next;
//         while(ptr) {
//             cout<<ptr->val<<endl;
//             ptr=ptr->next;
            
//         }
        
        return ans;
        
    }
};