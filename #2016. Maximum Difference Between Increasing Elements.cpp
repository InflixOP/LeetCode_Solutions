class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++)
            if(nums[j]>nums[i])
            maxi=max(maxi,nums[j]-nums[i]);
        }
        if(maxi==0)
        return -1;
        return maxi;
    }
};