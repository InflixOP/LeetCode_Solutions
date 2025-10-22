class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(auto it:nums)mp[it]++;
        int ans = 0;
        set<long long> st;
        for(auto it:nums){
            st.insert(it);
            if(it+k <= INT_MAX) st.insert(it+k);
            if(it-k >= INT_MIN) st.insert(it-k);
        }
        for(auto i : st){
            int ind1 = lower_bound(nums.begin(),nums.end(),i-k)-nums.begin();
            int ind2 = upper_bound(nums.begin(),nums.end(),i+k)-nums.begin()-1;
            int maxm = ind2-ind1+1;
            ans = max(ans, min(mp[i]+numOperations,maxm));
        }
        return ans;
    }
};