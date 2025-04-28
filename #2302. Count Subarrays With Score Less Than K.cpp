class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n=nums.size();
        long long ans=0;
        long long sum=0;
        long long l=0,r=0;
        while (r<n) {
            sum+=nums[r];
            while(l<=r&&sum*(r-l+1)>=k){
                sum-=nums[l];
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
};