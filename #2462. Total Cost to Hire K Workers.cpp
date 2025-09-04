class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long total = 0;
        int i = 0, j = costs.size() - 1;

        priority_queue<int, vector<int>, greater<>> leftHeap;
        priority_queue<int, vector<int>, greater<>> rightHeap;

        for (int hired = 0; hired < k; ++hired) {
            while (leftHeap.size() < candidates && i <= j)
                leftHeap.push(costs[i++]);
            while (rightHeap.size() < candidates && i <= j)
                rightHeap.push(costs[j--]);
            if (leftHeap.empty()) {
                total += rightHeap.top();
                rightHeap.pop();
            } else if (rightHeap.empty()) {
                total += leftHeap.top();
                leftHeap.pop();
            } else if (leftHeap.top() <= rightHeap.top()) {
                total += leftHeap.top();
                leftHeap.pop();
            } else {
                total += rightHeap.top();
                rightHeap.pop();
            }
        }

        return total;
    }
};