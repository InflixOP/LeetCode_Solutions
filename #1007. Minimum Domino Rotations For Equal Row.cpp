class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int reqAmt = bottoms.size();

        int topV = 0;
        int botV = 0;

        unordered_map<int, int> mp;
        for(auto &it: tops) {
            mp[it] += 1;
        }
        for(int i = 0; i < reqAmt; i++) {
            mp[bottoms[i]] += (tops[i] != bottoms[i]) ? 1 : 0;
        }

        int tempC = INT_MIN;
        int tempV = 0;
        for(auto &[val, count]: mp) {
            if(count > tempC) {tempC = count; tempV = val;}
        }
        
        if(mp[tempV] < reqAmt) return -1;
        for(auto &it: tops) {
            if(it == tempV) topV += 1;
        }
        for(auto &it: bottoms) {
            if(it == tempV) botV += 1;
        }

        return topV > botV? reqAmt - topV : reqAmt - botV;
    }
};