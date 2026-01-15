class MinStack {
public:
    MinStack() {
        
    }
    stack<int>st;
    stack<int>st1;
    int min = INT_MAX;
    
    void push(int val) {
        st.push(val);
        if(val<min){
            min=val;
        }
    }
    
    void pop() {
        st.pop();
        st1=st;
        min = INT_MAX;
        while(st1.size()){
            int x = st1.top();
            st1.pop();
            if(x<min){
                min=x;
            }

        }
        
    }
    
    int top() {
        int x = st.top();
        return x;
        
    }
    
    int getMin() {
        return min;

        
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