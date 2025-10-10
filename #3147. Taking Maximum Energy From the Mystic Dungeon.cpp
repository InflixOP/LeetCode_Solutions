class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> temp(energy.size(), 0);
        int ans = -1e9;
        
        for (int i = 0; i<energy.size(); i++) {
            if (i - k >= 0) temp[i] = temp[i - k];
            temp[i] = max (energy[i], temp[i] + energy[i]);
            if (i >= energy.size() - k) ans = max(ans, temp[i]);
        }
        return ans;
    }
};