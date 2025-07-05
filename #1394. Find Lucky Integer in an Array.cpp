class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto ele:arr)
        mp[ele]++;
        int maxi=-1;
        for(auto ele:mp){
            if(ele.first==ele.second)
            maxi=max(maxi,ele.first);
        }
        return maxi;    
    }
};