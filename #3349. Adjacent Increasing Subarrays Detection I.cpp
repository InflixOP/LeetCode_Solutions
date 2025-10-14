class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int a=0;
        int b=a+k;
        int n=nums.size();
        while(b<=n-k){
            int i=0;
            int flag=0;
            while(i<k-1){
                if(nums[a+i+1]>nums[a+i]&&nums[b+i+1]>nums[b+i]){
                    i++;
                    continue;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag){
                a++;
                b=a+k;
            }
            else{
                return true;
            }
        }
        return false;
    }
};