/*
1) Min-Heap Initialization:
  Use a lambda function to define the comparison for the min-heap.
2) Push Initial Elements:
  Push the head of each non-empty list into the min-heap.
3) Construct the Result List:
  Continuously extract the smallest element from the heap.
  Append this element to the result list.
  Push the next element from the extracted element's list into the heap.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to keep track of the smallest element across k lists
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // Push the head of each list into the min-heap
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        
        // Dummy node to help easily construct the result list
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // Extract the smallest element from the heap and add it to the result list
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            current->next = smallest;
            current = current->next;

            // Push the next element from the same list into the heap
            if (smallest->next) {
                pq.push(smallest->next);
            }
        }
        
        return dummy->next;
    }
};

int main() {
    // Example usage
    // Create lists: [1->4->5], [1->3->4], [2->6]
    ListNode* list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* list3 = new ListNode(2, new ListNode(6));
    
    vector<ListNode*> lists = {list1, list2, list3};
    
    Solution sol;
    ListNode* result = sol.mergeKLists(lists);
    
    // Print merged list
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
