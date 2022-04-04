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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* left= head;
        ListNode* right= head;
        ListNode* cur=head;
        
        int num=1;
        
        while(cur!=NULL)
        {
            if(num<k)
                left=left->next;
        
            if(num>k)
                right=right->next;
            
            num++;
            cur=cur->next;
            
        }
        
        int temp=left->val;
        left->val= right->val;
        right->val=temp;
        
        return head;
        
    }
};