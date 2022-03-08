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
        
       unordered_map<ListNode*, int> m;
        
        while(head!=NULL && m[head]==0)
        {
            m[head]=1;
            head= head->next;
            
        }
        
        if(m[head]==1)
            return true;
        else 
            return false;
        
    }
};