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
    ListNode* partition(ListNode* head, int x) {
        
        //make a dummy pointer
        ListNode* left= new ListNode();
        ListNode* right= new ListNode();
        
        ListNode* cur_l=left, *cur_r=right;
        
        if(head==NULL || head->next==NULL) return head;
        
        while(head!=NULL)
        {
            ListNode* temp;
            if(head->val< x) //add to left node
            {
                cur_l->next=head;
                temp=head->next;
                cur_l=cur_l->next;
                cur_l->next=NULL;
            }
            else //add to right node
            {
                cur_r->next=head;
                temp=head->next;
                cur_r=cur_r->next;
                cur_r->next=NULL;
            }
            
            head=temp;
        }
        
        cur_l->next=right->next;
        return left->next;
    }
};