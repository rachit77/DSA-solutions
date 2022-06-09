class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        //method-1 brute force O(N^3)
        
        //method-2 O(N^2) TLE
//        int i, mid=INT_MAX;
//         for(i=0;i<nums.size();i++)
//         {
//             mid=INT_MAX;
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 if(nums[i]<mid && mid<nums[j]) return true;
                
//                 if(nums[j]>nums[i])
//                     mid=min(mid,nums[j]);
//             }
//         }
//         return false;
        
        //method-3 O(N)
        int one = INT_MAX, two = INT_MAX;
        for (auto num : nums) {
            if (num < one)
                one = num;
            else if (one < num && num < two)
                two = num;
            else if (two < num)
            {
                //cout<<one<<" "<<two<<" "<<num<<endl;
                return true;
            }
                
        }
        return false;
    }
};