class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        
        //method-1 binary search
//         int l=0,h=nums.size()-1,ans=-1;
//         while(l<=h)
//         {
//             int mid =l+(h-l)/2;
            
//             if(nums[mid]==target)
//             {
//                 ans=mid;
//                 break;
//             }
            
//             if(target<nums[mid])
//                 h=mid-1;
//             else
//                 l=mid+1;
//         }
        
//         vector<int> res(2,-1);
//         //cout<<ans;
//         if(ans!=-1)
//         {
//             int a=ans,b=ans;
            
//             while(a>=1 && nums[a-1]==nums[ans]) a--;
//             while(b< nums.size()-1 && nums[b+1]==nums[ans]) b++;
            
//             res[0]=a;
//             res[1]=b;
//         }
        
//         return res;
        
      int s = 0, e = a.size()-1;
	vector<int> ans(2, -1);
	//first occurrence
	while(s <= e){
		int m = s + (e-s)/2;
		if(a[m] < target)
			s = m+1;
		else if(a[m] > target)
			e = m-1;
		else{
			if(m == 0 || a[m] != a[m-1]){
				ans[0] = m;
				break;
			}
			else{
				e = m-1;
				ans[0] = m-1;
			}
		}
	}

	//last occurrence
	s = 0, e = a.size()-1;
	while(s <= e){
		int m = s + (e-s)/2;
		if(a[m] < target)
			s = m+1;
		else if(a[m] > target)
			e = m-1;
		else{
			if(m == e || a[m] != a[m+1]){
				ans[1] = m;
				break;
			}
			else{
				s = m+1;
				ans[1] = m+1;
			}
		}
	}
	return ans;   
        
    }
};