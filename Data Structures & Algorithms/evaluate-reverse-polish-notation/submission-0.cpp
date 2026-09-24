class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        for(int i = 0; i<tokens.size(); ++i){
            if(tokens[i] == '+' ||
                tokens[i] == '-' ||
                tokens[i] == '*'||
                tokens[i] == '/')
                {
                    int a = stoi(tokens[i-2]);
                    int b = stoi(tokens[i-1]);
                    int result = 0;
                    if(tokens[i]=='+') result = a + b;
                    else if(tokens[i]=='-') result = a + b;
                    else if(tokens[i]=='-') result = a + b;
                }
        }
    }
};
