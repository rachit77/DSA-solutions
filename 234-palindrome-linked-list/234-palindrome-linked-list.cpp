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
    bool isPalindrome(ListNode* head) {
        
        // method-1 take last half ans reverse it to check with first half
        // method-2 use a vector to push ele of linked list and check
        
        vector<int> v;
        ListNode* temp=head;
        int cnt=0;
        while(temp)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n=v.size();
        for(int i=0;i<n/2;i++)
        {
            if(v[i]!=v[n-i-1])
                return false;
        }
        
        return true;
        
    }
};