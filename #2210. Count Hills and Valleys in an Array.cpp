class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> left(n,0);
        vector<int> right(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                left[i]=left[i-1];
            }
            else
            left[i]=nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]==nums[i+1]){
                right[i]=right[i+1];
            }else
            right[i]=nums[i+1];
        }
        for(int i=1;i<n-1;i++){
            if(left[i]==0||right[i]==0||nums[i]==nums[i-1])
            continue;
            else if((nums[i]>left[i]&&nums[i]>right[i])||(nums[i]<left[i]&&nums[i]<right[i]))
            {
                ans++;
                cout<<i<<" "<<nums[i]<<" "<<left[i]<<" "<<right[i]<<endl;
            }
        }
        return ans;
    }
};