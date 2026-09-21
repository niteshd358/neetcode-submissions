class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        
        bool x = false, y = false, z = false;

        for(auto& t : triplets){
            if(t[0] > target[0] || t[1] > target[1] || t[2] > target[2]){
                continue;
            }
            for(int i=0; i<t.size() ; ++i){
                if(t[i]==target[i]){
                    if(i == 0) x = true;
                    else if ( i == 1) y = true;
                    else z = true;
                }
            }
        }
        return (x && y && z);
    }
};
