class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // method-1 taking m+n extra space
        
        //method-2 add 2md in first and than sort
        
        //method-3 two pointe method
        int a=m-1,b=m+n-1, c=n-1;
        
        while(a>=0 && c>=0)
        {
            // check last elements of both array a and c
            if(nums2[c]>nums1[a])
            {
                nums1[b]=nums2[c];
                b--;
                c--;
            }
            else
            {
                nums1[b]=nums1[a];
                b--;
                nums1[a]=0;
                a--;
            }
            
        }
        
        while(c>=0)
        {
            nums1[b]=nums2[c];
            b--;
            c--;
        }
        
    }
};