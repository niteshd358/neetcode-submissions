class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);
        stack<pair<int,int>> st; // pair:{temp(nge),index}
        for(int i=n-1; i>=0; --i){
            while(!st.empty() && temperatures[i] >= st.top().first){
                st.pop();
            }
            result[i] = st.empty() ? 0 : st.top().second - i;
            st.push({temperatures[i],i});
        }        
        return result;
    }
};
