class Solution {
public:
    int merge(int l, int mid, int h, vector<int> &nums)
    {
        // nums[i]> 2* nums[j]
        
        //cal num of pairs
        int cnt=0;
        int j=mid+1;
        for(int i=l;i<=mid;i++)
        {
            while(j<=h && nums[i]> 2LL *nums[j])
            {
                j++;
            }
            cnt += (j-mid-1);
        }
        
        //merge the array
        vector<int> temp;
        int left=l,right=mid+1;
        
        while(left<=mid && right<= h)
        {
            if(nums[left]<= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        
        while(left<=mid)
            temp.push_back(nums[left++]);
        
        while(right<=h)
            temp.push_back(nums[right++]);
        
        for(int i=l;i<=h;i++)
            nums[i]=temp[i-l];
        
        return cnt;
    }
    
    int mergeSort(int l, int h, vector<int> &nums)
    {
        if(l>=h) return 0;
        
        int mid=(l+h)/2;
        
       int val= mergeSort(l,mid,nums);
        val+=mergeSort(mid+1,h,nums);
        
       val+= merge(l,mid,h,nums);
        return val;
    }
    
    int reversePairs(vector<int>& nums) {
        
       return mergeSort(0,nums.size()-1,nums);
        
    }
};