/*
    The median is the middle value in an ordered integer list. If the size of the list is even, there 
    is no middle value, and the median is the mean of the two middle values.

    For example, for arr = [2,3,4], the median is 3.
    For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
    Implement the MedianFinder class:

    MedianFinder() initializes the MedianFinder object.
    void addNum(int num) adds the integer num from the data stream to the data structure.
    double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual 
    answer will be accepted.

    Example 1:
    Input
    ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
    [[], [1], [2], [], [3], []]
    Output
    [null, null, null, 1.5, null, 2.0]

    Explanation
    MedianFinder medianFinder = new MedianFinder();
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    medianFinder.findMedian(); // return 2.0
*/

class MedianFinder {
public:
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;
    MedianFinder() {
        
    }
    void addNum(int num) {
        pq1.push(num);
        if(pq2.size() && pq1.top()>pq2.top()){
            pq2.push(pq1.top());
            pq1.pop();
        }
        if (pq1.size() > pq2.size() + 1) {
            pq2.push(pq1.top());
            pq1.pop();
        } else if (pq2.size() > pq1.size()) {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    
    double findMedian() {
        if(pq1.size() == pq2.size()){
            return (double)(pq1.top() + pq2.top())/2;
        }
        else{
            return pq1.top();
        }
    }
};

class MedianFinder {
public:
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;
    MedianFinder() {
        
    }
    void addNum(int num) {
        pq1.push(num);
        if(pq1.size()-pq2.size() > 1){
            pq2.push(pq1.top());
            pq1.pop();
        }
        if(pq1.size() && pq2.size() && pq1.top()>pq2.top()){
            pq2.push(pq1.top());
            pq1.pop();
        }
        
        if(pq2.size()>pq1.size()){
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    double findMedian() {
        if(pq1.size() == pq2.size()){
            return (double)(pq1.top() + pq2.top())/2;
        }
        else if(pq1.size() > pq2.size()){
            return pq1.top();
        }
        else{
            return pq2.top();
        }
    }
};

class MedianFinder {
public:
    multiset<int>ms;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ms.insert(num);
    }
    
    double findMedian() {
        int n = ms.size();
        if(n & 1) {
            int cnt=0;
            for(auto it : ms){
                if(cnt==n/2) {
                    return it;
                }
                cnt++;
            }
        }
        else{
            int a,b,cnt=0;
            for(auto it : ms){
                if(cnt==n/2-1) {
                    a = it;
                }
                if(cnt==n/2) {
                    b = it;
                    return (double)(a+b)/2;
                }
                cnt++;
            }
        }
    }
};