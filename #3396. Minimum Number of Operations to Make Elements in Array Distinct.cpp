class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            bool a[101]={false};
            for(int i=nums.size()-1;i>=0;i--){
                if(a[nums[i]]==true){
                    return ceil(double(i+1)/3);
                }
                a[nums[i]]=true;
            }
            return 0;
        }
    };