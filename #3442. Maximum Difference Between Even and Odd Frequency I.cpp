class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);
        int n=s.length();
        for(auto it:s)
        freq[it-'a']++;
        int odd=INT_MIN;
        int eve=INT_MAX;
        for(auto it:freq)
        if(it)
        it%2?odd=max(odd,it):eve=min(eve,it);
        return odd-eve;
    }
};