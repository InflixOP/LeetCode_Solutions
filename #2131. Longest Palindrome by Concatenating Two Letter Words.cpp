int cnt[26][26];

class Solution {
public:
    int longestPalindrome(vector<string>& a) {
        memset(cnt, 0, sizeof cnt);
        int ans = 0;
        int eql = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            if (cnt[a[i][1] - 'a'][a[i][0] - 'a'] > 0) {
                ans += 2 * 2;
                eql -= (a[i][0] == a[i][1]);
                cnt[a[i][1] - 'a'][a[i][0] - 'a']--;
            } else {
                eql += (a[i][0] == a[i][1]);
                cnt[a[i][0] - 'a'][a[i][1] - 'a']++;
            }
        };
        ans += (eql ? 2 : 0);
        return ans;
    }
};