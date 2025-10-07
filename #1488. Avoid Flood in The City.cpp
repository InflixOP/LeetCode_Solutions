class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        map<int, int> mp;
        set<int> s;
        for (int i = 0, n = size(rains); i < n; ++i) {
            if (rains[i]) {
                if (mp.count(rains[i])) if (auto it = s.upper_bound(mp[rains[i]]); it == end(s)) return {}; else rains[*it] = rains[i], s.erase(it);
                mp[rains[i]] = i, rains[i] = -1;
            } else rains[i] = 1, s.insert(i);
        }
        return rains;
    }
};