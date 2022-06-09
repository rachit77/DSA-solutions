class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n=gas.size();
        int tot_gas=0, tot_cost=0;
        
        for(int i:gas)
            tot_gas+=i;
        
        for(int i:cost)
            tot_cost+=i;
        
        if(tot_cost>tot_gas) return -1;
        
        int cur_fuel=0, start=0;
        for(int i=0;i<n;i++)
        {
            if(cur_fuel<0) //can't reach that station frm previous starting point
            {
               cur_fuel=0;
                start=i;
            }

            cur_fuel+=gas[i]-cost[i];
        }
        return start;
        
    }
};