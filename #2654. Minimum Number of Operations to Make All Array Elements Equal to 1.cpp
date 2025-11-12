class Solution {
public:
    int gcd_num(int a, int b) {
        if (b == 0) return a;
        return gcd_num(b, a % b);
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int overall_gcd = nums[0];
        for (int i = 1; i < n; i++) {
            overall_gcd = gcd_num(overall_gcd, nums[i]);
        }
        if (overall_gcd != 1) return -1;
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0) {
            return n - ones; 
        }
        int min_len = INT_MAX;
        for (int i = 0; i < n; i++) {
            int curr_gcd = nums[i];
            for (int j = i + 1; j < n; j++) {
                curr_gcd = gcd_num(curr_gcd, nums[j]);
                if (curr_gcd == 1) {
                    min_len = min(min_len, j - i + 1);
                    break; 
                }
            }
        }
        return (min_len - 1) + (n - 1);
    }
};