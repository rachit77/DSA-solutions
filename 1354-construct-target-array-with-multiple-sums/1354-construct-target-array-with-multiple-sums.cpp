class Solution {
public:
  
    bool isPossible(vector<int>& target) {
        int n=target.size(); 
        
        if(n==1)
            return target[0]==1;
        
        long long s= 0;
        
        //to find the maximun use a heap instead
        priority_queue<int> q; //num,index
        
        for(int i=0;i<target.size();i++)
        {
            q.push(target[i]);
            s+=target[i];
        }
        
        while(s>=n) //s>=n
        {
            if(s==n) return true;
            
            if(s<n) return false;
            
            int largest=q.top();
            q.pop();
    
            int rest=s-largest;
            
            if (rest == 1) {
                return true;
            }
            //cout<<largest<<" "<<rest<<endl;;
            int x= largest%rest; // x is the new element
           
            if(x<=0 || x == largest) return false;
            
            q.push(x);
            s=rest+x;
        }
        return false;
    }
};