class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int cur_r, int cur_c) {
        
        vector<vector<int>> ans;
        int dir=0;

        
        vector<int> r ={0,1,0,-1} ,c={1,0,-1,0}; // r,d,l,u
           
        int total_count=0;
        
        if(cur_r>=0 && cur_c>=0 && cur_r<rows && cur_c<cols )
        {
            ans.push_back({cur_r,cur_c});
            total_count++;
        }
                
        
        
        int steps=1,cnt=0;
        
        while(total_count<rows*cols)
        {            
            for(int i=1;i<=steps;i++)
            {
                cur_r=cur_r+r[dir];
                cur_c=cur_c+ c[dir];
                
                if(cur_r>=0 && cur_c>=0 && cur_r<rows && cur_c<cols )
                {
                    ans.push_back({cur_r,cur_c});
                    total_count++;
                }
            }
            
            if(cnt%2==1) steps++;
                
            cnt++;
            dir=(dir+1)%4;
        }
        
        return ans;
    }
};