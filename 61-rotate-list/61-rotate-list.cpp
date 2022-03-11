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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL) return head;
        
        
        int len=1;
        ListNode* last=head;
        
        while(last->next) 
        {
            len++;
            last=last->next;
        }
        
        
        k=k%len;
        if(k==0) return head;
        
        
        int revLen= len-k;
        
        ListNode *temp=head;
        //out<<revLen<<endl;
        
        while(revLen!=1) {
            temp=temp->next;
            revLen--;
        }
        
        last->next=head;
        
        head=temp->next;
        temp->next=NULL;
        
        return head;
        
    }
};