class Solution {
    private:
    long long max1(long long a,long long b){
        if(a>b) return a;
        return b;
    }
public:
    long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    long long diff = 0;
    long long max_val = 0;
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans = max1(ans,diff*nums[i]);
        diff = max1(diff,max_val-nums[i]);
        max_val = max1(max_val,nums[i]);
    }
    return ans;
    }
};