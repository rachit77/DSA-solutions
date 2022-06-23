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
    ListNode* rev(ListNode* temp)
    {
        ListNode* head=NULL;
        while(temp!=NULL)
        {
            ListNode* next=temp->next;
            temp->next=head;
            
            head=temp;
            temp=next;
        }
        
        return head;
    }
        
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //reverse the l1
        ListNode* l1_new=rev(l1);
//         while(l1!=NULL)
//         {
//             ListNode* next=l1->next;
//             l1->next=l1_new;
            
//             l1_new=l1;
//             l1=next;
//         }
        
        //reverse l2
        ListNode* l2_new=rev(l2);
//         while(l2!=NULL)
//         {
//             ListNode* next=l2->next;
//             l2->next=l2_new;
            
//             l2_new=l2;
//             l2=next;
//         }
        
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int rem=0;
        
        while(l1_new || l2_new)
        {
            int n1=0,n2=0;
            if(l1_new) n1=l1_new->val;
            if(l2_new) n2=l2_new->val;
            int n=n1 + n2 + rem;
            
            temp->val=n%10;
            rem=n/10;
            
            temp->next=new ListNode();
            temp=temp->next; 
            
            if(l1_new) l1_new=l1_new->next;
            if(l2_new) l2_new=l2_new->next;
        }
        
        if(rem!=0) {
            temp->val=rem;
        }
        
        
        //reverse the dummy list 
        ListNode* head=rev(dummy);
//         while(dummy)
//         {
//             ListNode* next=dummy->next;
            
//             dummy->next=head;
//             head=dummy;
//             dummy=next;
//         }
        
        if(head->val==0) head=head->next;
        
        return head;
    }
};