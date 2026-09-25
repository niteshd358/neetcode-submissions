class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack<pair<int,int>> st; // pair:{temp,index}
        for(int i=0; i<n; ++i){
            int t = temperatures[i];
            while(!st.empty() && t > st.top().first){
                auto pair_ = st.top();
                st.pop();
                res[pair_.second] = i - pair_.second;
            }
            st.push({t,i});
        }        
        return res;
    }
};
