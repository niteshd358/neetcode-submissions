class MedianFinder {
    vector<int> arr;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.push_back(num);
    }
    
    double findMedian() {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        if(n & 1){
            return arr[n/2];
        }else{
            return (arr[n/2] + arr[n/2 - 1]) / 2.0;
        }
    }
};
