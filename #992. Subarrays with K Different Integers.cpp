class Solution {
    public:
        int subarraysWithKDistinct(vector<int>& nums, int k) {
           return help(nums,k)-help(nums,k-1);
        }
        int help(vector<int>& nums, int k){
             unordered_map<int,int> mp;
            int l=0,r=0;
            int ans=0;
            int n=nums.size();
            while(r<n){
                mp[nums[r]]++;
                while(mp.size()>k){
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0)
                    mp.erase(nums[l]);
                    l++;
                }
                r++;
                ans+=(r-l+1);
            }
            return ans;
        }
    };