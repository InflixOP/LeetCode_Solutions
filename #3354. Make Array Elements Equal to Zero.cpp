class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        vector<int> ps(nums.size() + 1, 0);
        for (int i = 0; i<nums.size(); i++) ps[i+1] = ps[i] + nums[i];
        for (int i = 0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                if (ps[i+1] == ps.back() - ps[i+1] || ps[i+1] + 1 == ps.back() - ps[i+1]) ans++;
                if (ps[i+1] == ps.back() - ps[i+1] || ps[i+1] == ps.back() - ps[i+1] + 1) ans++;
            }
        }
        return ans;
    }
};  