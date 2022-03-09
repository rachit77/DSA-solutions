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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* p1;
       
        ListNode* dummy= new ListNode(-1);
        
        dummy->next=head;
        ListNode* temp=dummy;
        p1=head;
        
        while(p1!=NULL)
        {   
            if(p1->next !=NULL && p1->val == p1->next->val) {
                while(p1->next !=NULL && p1->val == p1->next->val )
                {
                    p1=p1->next;
                }
                
                temp->next=p1->next;
            }
            else {
                temp=temp->next;
            }
            
            p1=p1->next;
            
            
        }
        
       return dummy->next;
        
    }
};