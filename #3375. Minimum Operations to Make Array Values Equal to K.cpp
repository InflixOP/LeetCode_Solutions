class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            map<int,int>amap;
            int flag=0;
            for(auto i:nums){
                if(i>k){
                    amap[i]++;
                }
                if(i<k){
                    flag++;
                }
            }
            if(flag>0){
                return -1;
            }
            else{
                return amap.size();
            }
        }
    };