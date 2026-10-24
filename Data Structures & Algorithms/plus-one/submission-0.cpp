class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = 0;
        for(int i=0; i<digits.size(); ++i){
            n = (n*10) + digits[i];
        }
        n++;
        vector<int> res;
        while(n){
            res.push_back(n%10);
            n = n / 10;
        }
        reverse(res.begin() , res.end());
        return res;
    }
};
