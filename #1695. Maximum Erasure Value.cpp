class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        int maxi=0;
        unordered_set<int> st;
        int sum=0;
        while(r<n){
            if(st.find(nums[r])==st.end()){
                sum+=nums[r];
                maxi=max(sum,maxi);
                st.insert(nums[r]);
                r++;
            }else{
                st.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
        }
        return maxi;
    }
};