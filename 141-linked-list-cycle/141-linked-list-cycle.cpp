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
    bool hasCycle(ListNode *head) {
  
        //1st solution
//        unordered_map<ListNode*, int> m;
        
//         while(head!=NULL && m[head]==0)
//         {
//             m[head]=1;
//             head= head->next;
            
//         }
        
//         if(m[head]==1)
//             return true;
//         else 
//             return false;
        
        //2nd solution 
        
        if(head==NULL)
            return false;
        ListNode* fast= head;
        ListNode *slow=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if(fast==slow)
                return true;
            
            
        }
        return false;
    }
};