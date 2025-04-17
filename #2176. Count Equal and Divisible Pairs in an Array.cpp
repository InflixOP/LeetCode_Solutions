class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int pair=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if((nums[i]==nums[j]) && (i*j)%k==0) pair++;
            }
        }
        return pair;
    }
};