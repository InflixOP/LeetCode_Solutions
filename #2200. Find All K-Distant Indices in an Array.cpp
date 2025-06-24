class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] == key){
                int l = max(0, i-k);
                int high = min(k+i, n-1);

                mp[l] = high;
            }
        }

        vector<int> ans;
        int last = -1;

        for(auto [k, v] : mp){
            if(last == -1){
                for(int i = k; i<= v; i++){
                    ans.push_back(i);
                }
            }else{
                for(int i = max(last + 1, k); i <= v; i++){
                    ans.push_back(i);
                }
            }
            last = v;
        }

        return ans;
    }
};