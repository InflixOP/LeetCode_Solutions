class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        
      int n = nums.size();
      vector<int> suff = nums;
      for (int i = n - 2; i >= 0; i--) {
        suff[i] |= suff[i + 1];
      }
      vector<int> res(n), cnt(32, 0);
      int left = 0, right = 0, x = 0;
      while (left < n) {
        if (x < suff[left] || left == right) {
          x |= nums[right];
          int mask = nums[right];
          for (int i = 0; i < 32; i++) {
            if ((1 << i) & mask)
              cnt[i]++;
          }
          right++;
        }
        if (x == suff[left] && left <= right) {
          res[left] = right - left;
          int mask = nums[left];
          x = 0;
          for (int i = 0; i < 32; i++) {
            if ((1 << i) & mask)
              cnt[i]--;
            if (cnt[i] > 0)
              x |= (1 << i);
          }
          left++;
        }
      }
      res[n - 1] = 1;
      return res;
    }
};