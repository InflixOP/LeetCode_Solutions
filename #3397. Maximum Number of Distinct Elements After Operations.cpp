class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        if (nums.size() <= 2L * k + 1) {
            return nums.size();
        }
        
        sort(nums.begin(), nums.end());
        long long current = LLONG_MIN;
        int res = 0;
        
        for (int num : nums) {
            long long target = max(current + 1, (long long)num - k);
            
            if (target <= num + k) {
                current = target;
                res++;
            } else {
                current = max(current, (long long)num);
            }
        }
        
        return res;
    }
};