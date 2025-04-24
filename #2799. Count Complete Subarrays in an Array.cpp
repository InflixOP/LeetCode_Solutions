class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        int size=s.size();
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            set<int>d;
            for(int j=i;j<n;j++){
                d.insert(nums[j]);
                if(d.size()==size) count++;
            }
            
        }
        return count;
    }
};