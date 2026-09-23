class MinStack {
    long mini;
    stack<int> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(0);
            mini = val;
        }else{
            st.push(val-mini);
            if(val < mini) mini = val;
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        long top = st.top();
        st.pop();
        if(top < 0) mini = mini - top;
    }
    
    int top() {
        long top = st.top();
        return (top > 0) ? (top + mini) : (int)mini;
    }
    
    int getMin(){
        return (int)mini;
    }
};
