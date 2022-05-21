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
    void deleteNode(ListNode* node) {
        //node=node->next;
        
//         &(node)=node->next;
        
//         cout<<node<<endl;
//         cout<<&(node)<<endl;;
//         cout<<node->next;
        
//         while(node !=NULL && node->next!=NULL)
//         {
//             node->val=node->next->val;
//             node= node->next;
//         }
//         node=NULL;
        
        node->val=node->next->val;
        node->next= node->next->next;
        
    }
};