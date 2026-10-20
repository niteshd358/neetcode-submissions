class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i=0; i<=n; ++i){
            int cnt = 0;
            for(int j=0;j<32;++j){
                if(i&(1<<j)){
                    cnt++;
                }
            }
            res[i] = cnt;
        }
        return res;
    }
};
