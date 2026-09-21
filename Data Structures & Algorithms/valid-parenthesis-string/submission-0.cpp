class Solution {
public:
    bool checkValidString(string s) {
        int stars = 0;
        stack<char> st;
        for(char& c: s) {
            if(c == '('){
                st.push(c);
            }
            else if(c == '*'){
                stars++;
            }
            else{
                if(st.empty() && stars == 0){
                    return false;
                }
                else if(st.empty() && stars > 0){
                    stars--;
                }
                else{
                    st.pop();
                }
            }
        }
        return stars >= st.size() ? true : false;
    }
};
