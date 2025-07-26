class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0)
            continue;
            else{
                if(st.find(nums[i])==st.end()){
                    sum+=nums[i];
                    st.insert(nums[i]);
                }
            }
        }
        if(sum==0)
        return nums[nums.size()-1];
        return sum;
    }
};