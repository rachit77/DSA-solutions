class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[1]==b[1]) return a[0]<b[0];
        
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        
        //sort them acc to deadline
        sort(courses.begin(), courses.end(), comp);
        
        //make a max heap to push courses acc to duration
        priority_queue<pair<int,int>> q;  // duration, deadline
        
        int duration=0,ans=0;
        
        for(int i=0;i<courses.size();i++)
        {
            duration+= courses[i][0];
            
            if(duration>courses[i][1]) //pop out frm heap
            {
                if(!q.empty() && courses[i][0]< q.top().first)
                {
                    duration= duration-q.top().first;
                    q.pop();
                    q.push({courses[i][0],courses[i][1]});
                }
                else
                {
                    duration= duration-courses[i][0];
                }
            }
            else
            {
                q.push({courses[i][0],courses[i][1]});
                ans++;    
            }
        }
        
        return q.size();;
    }
};