class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
       int low = 1, high = nums.size() - 1, cnt;
        
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            cnt = 0;
            for(int n : nums)
            {
                if(n <= mid)
                    ++cnt;
            }
            
            cout<<low<<" "<<high<<" "<<mid<<" "<<cnt<<endl;
            if(cnt <= mid)
                low = mid + 1;
            else
                high = mid ;
            
        }
        return low;
        
    }
};