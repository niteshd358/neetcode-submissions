class Solution {
public:
    bool checkValidString(string s) {

        stack<int> st, stars;
        for(int i=0; i<s.size(); ++i) {
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == '*'){
                stars.push(i);
            }
            else{
                if(st.empty() && stars.empty()){
                    return false;
                }
                else if(st.empty()){
                    stars.pop();
                }
                else{
                    st.pop();
                }
            }
        }

        while(!st.empty() && !stars.empty()){
            if(st.top() > stars.top()) return false;
            st.pop();
            stars.pop();
        }

        return st.empty();
    }
};
