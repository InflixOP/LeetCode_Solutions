class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> remainderCnts(value, 0);
        for (const int& num : nums)
            remainderCnts[((num % value) + value) % value]++;
        int res = 0;
        while (remainderCnts[res % value]-- > 0)
            res++;
        return res;
    }
};