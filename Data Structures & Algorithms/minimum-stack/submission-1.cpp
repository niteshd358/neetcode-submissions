class MinStack {
    int mini;
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
        int top = st.top();
        st.pop();
        if(top < 0) mini = mini - top;
    }
    
    int top() {
        int top = st.top();
        return (top > 0) ? (top + mini) : (int)mini;
    }
    
    int getMin(){
        return (int)mini;
    }
};
