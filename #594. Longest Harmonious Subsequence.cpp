class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0,i = 0,j = 0;
        while(j<nums.size()){
            int diff = nums[j]-nums[i];
            if(diff==1) ans = max(j-i+1,ans);
            
            if(diff<=1) j++;
            else i++;
        }
        return ans;
    }
};