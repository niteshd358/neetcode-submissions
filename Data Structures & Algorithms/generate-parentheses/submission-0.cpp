class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        string s ;
        backtrack(0,0,n,s);
        return res;
    }
    void backtrack(int openN, int closedN, int n, string &s){
        if(openN == closedN && openN == n){
            res.push_back(s);
            return;
        }
        if(openN < n){
            //we can add open bracket
            s.push_back('(');
            backtrack(openN+1,closedN,n,s);
            s.pop_back();
        }
        if(closedN < openN){
            //we can add closed 
            s.push_back(')');
            backtrack(openN,closedN+1,n,s);
            s.pop_back();
        }

    }
};
