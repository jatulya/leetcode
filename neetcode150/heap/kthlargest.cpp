class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) :k(k) {
        for (int n: nums){
            add(n);
        }
    }
    
    int add(int val) {
        if (minHeap.size()<k){
            minHeap.push(val);
        }
        else if (val>minHeap.top()){
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};
