// LeetCode 23 - Merge k Sorted Lists
#include <queue>
#include <vector>
#include <functional>
using namespace std;

// LeetCode provides the ListNode definition.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

        for (ListNode* node : lists) {
            if (node != nullptr) {
                minHeap.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        tail->next = nullptr;
        return dummy.next;
    }
};
