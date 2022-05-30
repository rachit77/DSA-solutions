class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans(nums1.size());
        
        
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    ans[i]=j;
                    break;
                }
            }
        }
        
    
        
        // find next graeter element of nums2 vector
        
        stack<int> st; // contains index
        vector<int> ng(nums2.size(),-1);
        
        for(int i=0;i<nums2.size();i++)
        {
//             if(st.empty())
//                 st.push(i);
            
//             else
//             {
                    while(!st.empty() && nums2[i]> nums2[st.top()])
                    {
                       int temp=st.top();
                        st.pop();
                       ng[temp]=i; 
                        
                    }
                    
                    st.push(i);
                
           // }
        }
    
        
        for(int i=0;i<nums1.size();i++)
        {
            int temp=ng[ans[i]];
            
            if(temp!=-1)
                ans[i]=nums2[temp];
            else
                ans[i]=-1;
        }
        
        return ans;
        
        
    }
};