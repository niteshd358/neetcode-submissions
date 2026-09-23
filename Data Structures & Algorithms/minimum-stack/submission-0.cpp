class MinStack {
    stack<int> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin(){
        stack<int> temp;
        temp = st;
        int mini = INT_MAX;
        while(temp.size()){
            mini = min(mini, temp.top());
            temp.pop();
        }
        return mini;
    }
};
