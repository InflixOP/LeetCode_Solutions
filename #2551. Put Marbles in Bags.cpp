class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0; // Only one bag, so no difference
        
        vector<int> pairSums(n-1);
        
        // Compute the sum of adjacent pairs
        for (int i = 0; i < n - 1; i++) {
            pairSums[i] = weights[i] + weights[i + 1];
        }
        
        // Sort the sums
        sort(pairSums.begin(), pairSums.end());
        
        long long minScore = 0, maxScore = 0;
        
        // Pick k-1 smallest and largest pairs
        for (int i = 0; i < k - 1; i++) {
            minScore += pairSums[i];
            maxScore += pairSums[n - 2 - i];
        }
        
        return maxScore - minScore;
    }
};