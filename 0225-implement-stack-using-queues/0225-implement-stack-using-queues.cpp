class MyStack {
public:
    MyStack() {
        
    }
queue<int>qu;
       
    void push(int x) {
        qu.push(x);

        for(int i=1;i<qu.size();i++){
            qu.push(qu.front());
            qu.pop();
        }

        
    }
    
    int pop() {
        int n = qu.front(); 
        // Remove front element
        qu.pop(); 
        // Return removed element
        return n;      
    }
    
    int top() {
       return qu.front();
        
    }
    
    bool empty() {
        return qu.empty() ;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */