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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        //using unordered map
        
//         unordered_map<ListNode*,int> m;
        
//         ListNode* temp=headA;
//         while(temp)
//         {
//             m[temp]=1;
//             temp=temp->next;
//         }
            
        
//         temp= headB;
//         while(temp)
//         {
//             if(m[temp]==1)
//             {
//                 return temp;
//             }
//         }
        
//         return NULL;
        
        
        // method-2 diff in length
        int a=0,b=0;
        
        ListNode *temp1=headA,*temp2=headB;
        
        while(temp1)
        {
            a++;
            temp1=temp1->next;
        }
        
        temp1=headA;
       
        while(temp2)
        {
            b++;
            temp2=temp2->next;
        }
        temp2=headB;
        
       while(a>b)
       {
           if(a==b) break;
           temp1=temp1->next;
           a--;
       }
        
        while(a<b)
       {
           if(a==b) break;
           temp2=temp2->next;
           b--;
       }
        
        while(temp1!=temp2)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        return(temp1==temp2)?temp1:NULL;
        
    }
};