/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        //method-1 can use a hash map
        //method-2 slow and fast pointer
        
        //method-1
        unordered_map<ListNode*,int> m;
        ListNode *s=head,*f=head;
        while(f!=NULL && f->next!=NULL)
        {
            if(m[s]==1)
                return s;
            m[s]=1;
            
            s=s->next;
            f=f->next->next;
        } 
        return NULL;
    }
};