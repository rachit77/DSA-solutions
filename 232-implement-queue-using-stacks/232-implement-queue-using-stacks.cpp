class MyQueue {
public:
    stack<int> st1;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> st2;
        stack<int> st3;
        
        st2.push(x);
        
        while(!st1.empty())
        {
            st3.push(st1.top());
            st1.pop();
        }
        
        while(!st3.empty())
        {
            st2.push(st3.top());
            st3.pop();
        }
        
        st1=st2;
        
    }
    
    int pop() {
        int temp=st1.top();
        st1.pop();
        return temp;
        
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */