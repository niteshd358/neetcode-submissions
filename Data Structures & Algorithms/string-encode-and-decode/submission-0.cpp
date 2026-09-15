class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for(const string &s : strs){
            encoded_string.append(to_string(s.size()));
            encoded_string.push_back(',');
            encoded_string.append(s);
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        int i=0;
        while(i<s.length()){
            int j = i;
            while(s[j] != ','){
                j++;
            }
            int length = stoi(s.substr(i,j-i));
            i = j + 1;
            j = i + length;
            decoded_strs.push_back(s.substr(i,length));
            i = j;
        }
        return decoded_strs;
    }
};
