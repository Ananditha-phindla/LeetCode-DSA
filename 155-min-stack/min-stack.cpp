class MinStack {
public:
    long long  min_ele = -1;
    stack<long long>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            min_ele = val;
            st.push(val);
        }
        else{
            if(val >= min_ele){
                st.push(val);
            }
            else{
                long long flag = ((2LL*val)-min_ele);
                min_ele = val;
                st.push(flag);
            }
        }
    }
    
    void pop() {
        if(st.top() < min_ele){
            long long flag = 2*min_ele - st.top();
            min_ele = flag;
            st.pop();
        }
        else
            st.pop();
        
    }
    
    int top() {
        if(st.top() < min_ele){
            return min_ele;
        }
        return st.top();
        
    }
    
    int getMin() {
        return min_ele;
        
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