class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        int l=0;
        if(nums[0]==1)
        l++;
        for(int i=1;i<n;i++){
            if(nums[i]==0){
                left[i]=l;
                l=0;
            }else{
                left[i]=l;
                l++;
            }
        }
        int r=0;
        if(nums[n-1]==1)
        r++;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==0){
                right[i]=r;
                r=0;
            }else{
                right[i]=r;
                r++;
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        maxi=max(maxi,left[i]+right[i]);
        return maxi;
    }
};