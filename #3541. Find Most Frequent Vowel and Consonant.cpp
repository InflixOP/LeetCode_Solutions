class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        int maxi1=0,maxi2=0;
        for(auto ele:mp){
            if(ele.first=='a'||ele.first=='e'||ele.first=='i'||ele.first=='o'||ele.first=='u')
            maxi1=max(maxi1,ele.second);
            else
            maxi2=max(maxi2,ele.second);
        }
        return maxi1+maxi2;
    }
};