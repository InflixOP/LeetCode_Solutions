class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            return help(nums,goal)-help(nums,goal-1);
        }
        int help(vector<int>& nums, int goal){
            int l=0,r=0;
            int c=0,sum=0;
            while(r<nums.size()){
                sum+=nums[r];
                while(sum>goal&&l<=r){
                    sum-=nums[l];
                    l++;
                }
                c+=(r-l+1);
                r++;
            }
            return c;
        }
    };