class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n=nums.size();
            int maj=-1;
            int c=0;
            for(int i=0;i<n;i++){
                if(c==0){
                    maj=nums[i];
                    c=1;
                }else if(nums[i]==maj)
                c++;
                else
                c--;
            }
            c=0;
            for(auto ele:nums){
                if(ele==maj)
                c++;
            }
            int c1=0;
            for(int i=0;i<n;i++){
                if(nums[i]==maj)
                c1++;
                int r=c-c1;
                if(c1*2>i+1&&r*2>n-i-1)
                return i;
            }
            return -1;
        }
    };