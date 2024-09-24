class MedianFinder {
    private PriorityQueue<Integer> minheap, maxheap;
    public MedianFinder() {
        minheap = new PriorityQueue<>();
        maxheap = new PriorityQueue<>((a,b) -> b - a);
    }
    
    public void addNum(int num) {
        maxheap.offer(num);

        if (!minheap.isEmpty() && maxheap.peek() > minheap.peek()){
            minheap.offer(maxheap.poll());
            maxheap.offer(minheap.poll());
        }
        
        while(maxheap.size() > minheap.size()+1){
            minheap.offer(maxheap.poll());
        }
    }
    
    public double findMedian() {
        if (maxheap.size() > minheap.size())
            return maxheap.peek();
        return (maxheap.peek() + minheap.peek())/2.0;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
