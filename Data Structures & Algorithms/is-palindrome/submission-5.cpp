class Solution {
private: 
    bool isAlphanumeric(char c){
        return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9'); 
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
