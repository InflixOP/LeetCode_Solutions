class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size()-2;i++){
            if((double)nums[i]+nums[i+2]==(double)nums[i+1]/2)
            c++;
        }
        return c;
    }
};