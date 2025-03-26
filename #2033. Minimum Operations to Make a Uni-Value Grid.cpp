class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        if (grid.empty() || grid[0].empty()) return -1;
        vector<int> nums; // convert into  1-D
        int m = grid.size();
        int n = grid[0].size();
        
        int sElement = grid[0][0]; // starting element
        int mod = (sElement % x + x) % x; // Ensure non-negative modulo
        
        for (auto row : grid) {
            for (int num : row) {
                int currEl = (num % x + x) % x;
                if (currEl != mod) {
                    return -1;
                }
                nums.push_back(num);
            }
        }
        
        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];
        int cntOperation = 0;
        for (int num : nums) {
            cntOperation += abs(num - median) / x;
        }
        return cntOperation;
    }
};