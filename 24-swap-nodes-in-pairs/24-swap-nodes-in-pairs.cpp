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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL ||head->next==NULL) return head;
        
       ListNode* dummy=new ListNode();
        dummy->next=head;
        
        ListNode *f=dummy, *s=head;
        
        while(s!=NULL && s->next!=NULL)
        {
            ListNode *temp=s->next;
            s->next=temp->next;
            f->next=temp;
            temp->next=s;
            
            f=f->next->next;
            s=s->next;
        }
        
        return dummy->next;
    }
};