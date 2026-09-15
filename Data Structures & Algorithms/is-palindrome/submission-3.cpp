class Solution {
private: 
    bool isAlphanumeric(char c){
        if(c >= 'A' && c <= 'Z') return true;
        if(c >= 'a' && c <= 'z') return true;
        if(c >= '0' && c <= '9') return true;
        return false;
    }
public:
    bool isPalindrome(string s) {
        int low = 0, high = s.length() - 1;
        while(low < high){
            while(low < high && !isAlphanumeric(s[low])){
                low++;
            }
            while(low < high && !isAlphanumeric(s[high])){
                high--;
            }
            if(tolower(s[low]) != tolower(s[high])) return false;
            low++;high--;
        }
        return true;
    }
};
