class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int l=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                ans=min(ans,i-l+1);
                sum-=nums[l];
                l++;
            }
        }
        if(ans==INT_MAX)
        return 0;
        return ans;
    }
};