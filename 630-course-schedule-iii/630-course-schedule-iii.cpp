class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[1]==b[1]) return a[0]<b[0];
        
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        
        //sort them acc to ascending deadline
        sort(courses.begin(), courses.end(), comp);
       
        
        //method-1
        
//         //make a max heap to push courses acc to duration
//         priority_queue<pair<int,int>> q;  // duration, deadline
        
//         int duration=0,ans=0;
        
//         for(int i=0;i<courses.size();i++)
//         {
//             duration+= courses[i][0];
            
//             if(duration>courses[i][1]) //pop out frm heap
//             {
//                 if(!q.empty() && courses[i][0]< q.top().first)
//                 {
//                     duration= duration-q.top().first;
//                     q.pop();
//                     q.push({courses[i][0],courses[i][1]});
//                 }
//                 else
//                 {
//                     duration= duration-courses[i][0];
//                 }
//             }
//             else
//             {
//                 q.push({courses[i][0],courses[i][1]});
//                 ans++;    
//             }
//         }
        
//         return q.size();
    
    //method-2 using an extra list
        vector<int> valid;
        int time=0;
        
        for(int i=0;i<courses.size();i++)
        {
            //cout<<i<<" "<<time<<endl;
            if(time+courses[i][0]<=courses[i][1]) //valid entr
            {
                time+=courses[i][0];
                valid.push_back(courses[i][0]);
            }
            else //not a valid entry
            {
                
              //find the maxi in the valid list
                int max_i=0;
                for(int j=1;j<valid.size();j++)
                {
                    if(valid[j]> valid[max_i])
                        max_i=j;    
                }
                
                if(valid.size()>0 && valid[max_i] >courses[i][0])
                {
                   // cout<<i<<"else"<<endl;
                    time=time-valid[max_i]+courses[i][0];
                    valid[max_i]=courses[i][0];
                    ///cout<<"time"<<va<<endl;
                }
            }
        }
        
        // for(auto x: valid)
        //     cout<<x<<endl;
        return valid.size();
    }
};