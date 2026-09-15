class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0 ; i< numbers.size() ; ++i){
            int low = i+1, high = numbers.size()-1;
            int need_to_target = target - numbers[i];
            while(low <= high){
                int mid = (low + high) / 2;
                if(numbers[mid] == need_to_target) return {i+1,mid+1};
                if(numbers[mid] > need_to_target){
                    high = mid -1;
                }else{
                    low = mid + 1;
                }
            }
        }
        return {};
    }
};
