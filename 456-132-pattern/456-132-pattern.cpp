class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //2nd element is the greatest
        stack<int> st;  //top of stack is 2nd element
        
        int thirdElement= INT_MIN;
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]< thirdElement) return 1;
            
            while(!st.empty() && st.top()< nums[i])
            {
                thirdElement= st.top();
                st.pop();
            }
            
            st.push(nums[i]);
        }
        return false;   
    }
};