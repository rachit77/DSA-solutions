/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* arrange(ListNode *head)
    {
        if(!head || !head->next) return head;
        
        ListNode *temp=head->next;
        head->next=arrange(head->next->next);
        temp->next=head;
        
        return temp;
    }
    
    ListNode* swapPairs(ListNode* head) { 
        if(head==NULL ||head->next==NULL) return head;

        //method-1 iterative
//        ListNode* dummy=new ListNode();
//         dummy->next=head;
        
//         ListNode *f=dummy, *s=head;
        
//         while(s!=NULL && s->next!=NULL)
//         {
//             ListNode *temp=s->next;
//             s->next=temp->next;
//             f->next=temp;
//             temp->next=s;
            
//             f=f->next->next;
//             s=s->next;
//         }
//         return dummy->next;
        
        //method-2 recursive
        if(!head || !head->next) return head;
        
        ListNode *temp=head->next;
        head->next=swapPairs(head->next->next);
        temp->next=head;
        
        return temp;
       // return arrange(head);
    }
};