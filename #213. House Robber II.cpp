class Solution {
    public:
        int rob(vector<int>& nums) {
            int n=nums.size();
             if(n==1){
                return nums[0];
            }
            else if(n==2){
                return max(nums[0],nums[1]);
            }
            vector<int> v1;
            vector<int> v2;
            for(int i=0;i<n;i++){
                if(i!=0)
                v1.push_back(nums[i]);
                if(i!=n-1)
                v2.push_back(nums[i]);
            }
            return max(helper(v1),helper(v2));
                }
        int helper(vector<int> nums){
             int n=nums.size();
            if(n==1){
                return nums[0];
            }
            else if(n==2){
                return max(nums[0],nums[1]);
            }
            int prev=nums[0];
            int prev2=0,curr=0;
            int take=0,nt=0;
           for(int i=1;i<n;i++){
        take=nums[i];
        if(i>1)
        take+=prev2;
        nt=prev;
        curr=max(take,nt);
        prev2=prev;
        prev=curr;
      }
      return prev;
        }
    };