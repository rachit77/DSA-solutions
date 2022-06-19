class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
        int i=0,j=0,cnt=0,a,b;
        int n1=nums1.size();
        int n2=nums2.size();
        int n =n1+n2;
        
        int id=n/2;
        // a= id-1 ele ,b is id wla element
        
        while(i<n1 && j<n2)
        {
            int cur_num;
            if(nums1[i]<=nums2[j])
            {
                cur_num=nums1[i];
                i++;
            }
            else
            {
                cur_num=nums2[j];
                j++;
            }
            
            if(cnt==id-1) a=cur_num;
            if(cnt == id) b=cur_num;
            
            cnt++;
        }
        
        while(cnt<=id)
        {
            int cur_num;
            if(i<n1)
            {
                cur_num=nums1[i];
                i++;
            }
            else 
            {
                cur_num= nums2[j];
                j++;
            }
            
            if(cnt==id-1) a=cur_num;
            if(cnt == id) b=cur_num;
            
            cnt++;
        }
        
        double ans=0;
        if(n%2==0)
            ans=(a+b)/(double)2;
        else
            ans=(double)b;
        
        return ans;
    }
};