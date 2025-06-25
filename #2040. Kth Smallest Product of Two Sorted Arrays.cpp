class Solution {
    long countLessThanEqual(vector<int>& nums1, vector<int>& nums2, long target) {
        long count = 0;
        for(int i = 0; i < nums1.size(); i++) {
            long num1 = nums1[i];
            int low = 0, high = nums2.size() - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2; 
                long prod = num1 * nums2[mid];
                if((num1 >= 0 && prod <= target) || (num1 < 0 && prod > target)) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if(num1 >= 0) count += low;
            else count += nums2.size() - low;
        }
        return count;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long low = -1e10, high = 1e10;
        while(low <= high) {
            long mid = low + (high - low) / 2;
            long count = countLessThanEqual(nums1, nums2, mid);
            if(count < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};