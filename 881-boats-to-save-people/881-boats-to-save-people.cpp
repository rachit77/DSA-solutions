class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end()) ;
        
        int i=0,n=people.size()-1,ans=0;
        
        while(i<=n)
        {
            if(people[i]+people[n]<=limit)
            {
                ans++;
                i++;
                n--;
            }
            else
            {
                if(people[n]<=limit)
                {
                    n--;
                    ans++;
                }
                else
                {
                    return -1;
                    break;
                }
            }
            
            
        }
        
        return ans;
        
    }
};