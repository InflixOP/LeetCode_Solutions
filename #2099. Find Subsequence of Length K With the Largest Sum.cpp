class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>st;
        for(int i=0;i<nums.size();i++){
            st.push_back({i,nums[i]});
        }
        sort(st.begin(),st.end(),[&](auto x1,auto x2){
            return x1.second>x2.second;
        });
        vector<int>ans;
        sort(st.begin(),st.begin()+k);
        for(int i=0;i<k;i++){
            ans.push_back(st[i].second);
        }
        return ans;
    }
};