class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n=nums.size();
            vector<int> ind;
            int l=0,r=0;
            int maxi=0;
            int zc=0;
            while(r<n){
                if(nums[r]==0)
                zc++;
                if(zc>k){
                    if(nums[l]==0) zc--;
                    l++;
                }
                else{
                    maxi=max(maxi,r-l+1);
                }
                r++;
            }
            return maxi;
        }
    };