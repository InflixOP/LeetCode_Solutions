class Solution {
    public:
        int numberOfSubarrays(vector<int>& nums, int k) {
            return help(nums,k)-help(nums,k-1);
        }
        int help(vector<int>& nums, int k){
            int n=nums.size();
            int l=0,r=0;
            int c=0;
            int odd=0;
            while(r<n){
                odd+=(nums[r]%2);
                while(odd>k){
                        odd-=(nums[l]%2);
                        l++;
                }
                    c+=(r-l+1);
                r++;
            }
            return c;
        }
    };
    