class MinStack {
public:
    MinStack() {
        
    }
    stack<pair<int,int>>st;
  
    int mini = INT_MAX;
    
    void push(int val) {
       mini = min(mini, val);
    st.push({val, mini});
    }
    
    void pop() {
    if (st.empty()) return;

    st.pop();

    if (st.empty()) {
        mini = INT_MAX;   // reset minimum
    } else {
        mini = st.top().second;
    }
}

        
        int top() {
            if (st.empty()) return -1;
        int x = st.top().first;
        return x;
        
    }
    
    int getMin() {
        if (st.empty()) return -1;
        return st.top().second;

        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */