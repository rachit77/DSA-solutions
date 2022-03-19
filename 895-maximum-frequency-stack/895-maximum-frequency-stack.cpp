class FreqStack {
public:
    
    struct compare {
bool operator()(pair<int,pair<int,int>> const& a, pair<int,pair<int,int>> const& b){
            
            if(a.first==b.first)
                return a.second.first < b.second.first;
            else
            return a.first < b.first;
        }
    };
    
    //max heap type implementations
priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , compare> q;
    unordered_map<int,int> freq;
    int pos=0;
    
    
    FreqStack() {
        
    }
    
    void push(int val) {
        
        ++freq[val];
        pos++;
        q.push({freq[val],{pos,val}});
    }
    
    int pop() {
        
        pair<int,pair<int,int>> ans=q.top();
        q.pop();
        
        freq[ans.second.second]--;
        return ans.second.second;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */