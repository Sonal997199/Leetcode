class MinStack {
public:
    stack<int> st;
    int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(mini>=val)
        {
            st.push(mini);
            mini=val;
        }
        st.push(val);
    }
    
    void pop() {
        if(mini==st.top())
        {
            st.pop();
            mini=st.top();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini;
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