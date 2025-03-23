/***
calculate the median of a data stream using a min-heap and a max-heap.

Approach:
	1.	Max-Heap (Left side): Stores the smaller half of the numbers.
	2.	Min-Heap (Right side): Stores the larger half of the numbers.

	•	The Max-Heap stores elements in a way that the largest value remains at the top.
	•	The Min-Heap stores elements in a way that the smallest value remains at the top.

Steps:
	1.	If the new number is less than or equal to the maximum of the Max-Heap, insert it into the Max-Heap. Otherwise, insert it into the Min-Heap.
	2.	Balance the Heaps:
	•	If one heap has more than one extra element compared to the other, rebalance by moving an element from the larger heap to the smaller one.
	3.	Calculate Median:
	•	If both heaps have the same size, the median is the average of the tops of both heaps.
	•	If the heaps have different sizes, the median is the top of the heap with more elements.

***/
#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // Left half (smaller numbers)
    priority_queue<int, vector<int>, greater<int>> minHeap; // Right half (larger numbers)

public:
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

int main() {
    MedianFinder mf;
    int arr[] = {5, 15, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for (int i = 0; i < n; i++) {
        mf.addNum(arr[i]);
        cout << "Median after reading " << arr[i] << ": " << mf.findMedian() << endl;
    }
    return 0;
}