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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL,*curr=head;
        
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
       int count=1;
        ListNode* prev=NULL,*curr=head;
        
        while(count!=left)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }
        
        //now find the right node
        ListNode* start=curr;
        
        while(count!=right)
        {
            curr=curr->next;
            count++;
        }
        
        ListNode* rest=curr->next;
        curr->next=NULL;
        
        //now reverse the nodes starting from start node
        ListNode* newHead= reverse(start);
        
        if(prev!=NULL)
        {
            prev->next=newHead;
        }
        
        curr=newHead;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        
        curr->next=rest;
        
        if(prev==NULL) return newHead;
        else
            return head;
    }
};