class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd=0;
        int even=0;
        int oddeve=0;
        for(auto ele:nums){
            if(ele%2==0)
            even++;
            else
            odd++;
        }
        bool expectOdd=true;
        bool expectEven=true;
        for (int i=0;i<nums.size();i++) {
            if(nums[i]%2==0&&expectEven) {
                oddeve++;
                expectEven=false;
                expectOdd=true;
            }else if(nums[i]%2!=0&&expectOdd) {
                oddeve++;
                expectOdd=false;
                expectEven=true;
            }
        }
        return max({even,odd,oddeve});
    }
};