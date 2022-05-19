class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        
         unordered_map<int,int> m;
        int i,temp;
        vector<int> k;
        for(i=0;i<num.size();i++)
        {
            
                
            temp=target-num[i];
            
            if(m.find(temp)!=m.end())
            {
               
            k.push_back(m[temp]);
                 k.push_back(i);
                break;
            }
            m[num[i]]=i;
                
        }
        return k;
        
    }
};