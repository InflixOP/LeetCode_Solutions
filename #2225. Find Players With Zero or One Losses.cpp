class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        unordered_set<int> st;
        for(auto ele:matches){
            int w=ele[0];
            int l=ele[1];
            st.insert(w);
            mp[l]++;
        }
        vector<int> z;
        for(auto ele:st){
            if(mp.find(ele)==mp.end())
            z.push_back(ele);
        }
        sort(z.begin(),z.end());
        ans.push_back(z);
        vector<int> one;
        for(auto ele:mp){
            if(ele.second==1)
            one.push_back(ele.first);
        }
        sort(one.begin(),one.end());
        ans.push_back(one);
        return ans;
    }
};
