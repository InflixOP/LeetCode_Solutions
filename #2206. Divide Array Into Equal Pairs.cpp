class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int,int> mp;
            for(auto ele:nums){
                mp[ele]++;
            }
            for(auto ele:mp){
                if(ele.second%2!=0)
                return false;
            }
            return true;
        }
    };