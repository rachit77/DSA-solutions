class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
//         int l=0,curr=0;
//         int cnt=0;
//         for(auto it:nums) if(it<piv) cnt++;
        
//         int r=cnt;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]<piv)
//             {
//                 int temp=nums[l];
//                 nums[l]=nums[i];
//                 nums[i]=temp;
                
//                 l++;
//             }
//             else  //swap with right
//             {
//                int temp=nums[i];
//                 nums[i]=nums[r];
                
//             }
//         }
        
//         return nums;
        
        vector<int>v1;
    vector<int>v2;
     vector<int>v3;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<pivot){
            v1.push_back(nums[i]);
        }
        else if(nums[i] == pivot){
            v2.push_back(nums[i]);
        }else{
            v3.push_back(nums[i]);
        }
    }
    //connection is remaining
    for(int i=0;i<v2.size();i++){
        v1.push_back(v2[i]);
    }
    for(int i=0;i<v3.size();i++){
        v1.push_back(v3[i]);
    }
    return v1;
    }
};