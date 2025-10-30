class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = target[0];
        for(int i = 1; i <= n-1; i++)
        {
            ans += max (0, (target[i] - target[i-1]));
        }
        return ans;
    }
};