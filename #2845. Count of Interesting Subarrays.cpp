class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        int n=nums.size();
        vector<int>pref(n,0);
        map<int,int>mp;
        int cnt=0;
        long long ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            pref[i]=(nums[i]%mod==k)+cnt;
            int l=pref[i]%mod;
            if(mp.find((l-k+mod)%mod)!=mp.end()){
                ans+=mp[(l-k+mod)%mod];
            }
            cnt=pref[i];
            mp[l]++;
        }
        return ans;
    }
};