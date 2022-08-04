class MyCalendar {
public:
    vector<pair<int,int>> v;
    MyCalendar() {
        v.clear();
    }
    
    bool book(int s, int e) {
    
        // m-1 linear transaversing at each (TLE)
        for(auto it:v){
            int s1=it.first, e1=it.second;
            if(!((s<s1 && e<=s1) ||(s1<s && e1<=s)))
            {
                return false;
            }
        }
        
        //now add the dates in calender
        v.push_back({s,e});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */