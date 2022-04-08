class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        //make max heap
//         make_heap(stones.begin(), stones.end());
        
//         while(stones.size() >1)
//         {
//             int x= stones.front();
//             pop_heap(stones.begin(),stones.end());
//             stones.pop_back();
            
//             int y = stones.front();
//             pop_heap(stones.begin(),stones.end());
//             stones.pop_back();
            
//             if(x==y)
//                 continue;
            
//             stones.push_back(x-y);
//             push_heap(stones.begin(), stones.end());
            
//         }        
//         return stones.size()? stones.front():0;
        
        
        priority_queue<int> pq(v.begin(),v.end());
        
        while(true)
        {
            if(pq.size() ==0)   return 0;
            if(pq.size() ==1)   return pq.top();
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a!=b)    pq.push(a-b);
        }
    }
};